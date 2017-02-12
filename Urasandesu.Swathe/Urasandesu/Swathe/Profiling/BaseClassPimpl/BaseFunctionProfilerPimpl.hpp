﻿/* 
 * File: BaseFunctionProfilerPimpl.hpp
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_HPP
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_HPP

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseFunctionProfilerPimpl.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseFunctionProfilerPimpl<ApiHolder>::BaseFunctionProfilerPimpl(function_profiler_label_type *pClass) : 
        m_pClass(pClass), 
        m_pProcProf(nullptr), 
        m_id(-1), 
        m_classId(-1), 
        m_moduleId(-1), 
        m_functionBodyId(-1), 
        m_mdt(mdTokenNil), 
        m_pMethodGen(nullptr)
    { }

#define SWATHE_DECLARE_BASE_FUNCTION_PROFILER_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseFunctionProfilerPimpl<ApiHolder>::Initialize(process_profiler_label_type *pProcProf)
    {
        _ASSERTE(pProcProf);
        _ASSERTE(!m_pProcProf);
        m_pProcProf = pProcProf;
    }



    template<class ApiHolder>    
    UINT_PTR BaseFunctionProfilerPimpl<ApiHolder>::GetID() const
    {
        _ASSERTE(m_id != -1);
        return m_id;
    }



    template<class ApiHolder>    
    typename BaseFunctionProfilerPimpl<ApiHolder>::process_profiler_label_type *BaseFunctionProfilerPimpl<ApiHolder>::GetProcessProfiler()
    {
        _ASSERTE(m_pProcProf);
        return m_pProcProf;
    }



    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfilerPimpl<ApiHolder>::class_profiler_label_type> BaseFunctionProfilerPimpl<ApiHolder>::AttachToClass()
    {
        if (m_classId == -1)
            FillProperties(this, m_classId, m_moduleId, m_mdt);
        return m_pProcProf->AttachToClass(m_classId);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfilerPimpl<ApiHolder>::module_profiler_label_type> BaseFunctionProfilerPimpl<ApiHolder>::AttachToModule()
    {
        if (m_moduleId == -1)
            FillProperties(this, m_classId, m_moduleId, m_mdt);
        return m_pProcProf->AttachToModule(m_moduleId);
    }



    template<class ApiHolder>    
    typename BaseFunctionProfilerPimpl<ApiHolder>::method_generator_label_type *BaseFunctionProfilerPimpl<ApiHolder>::GetMethodGenerator(assembly_generator_label_type *pAsmGen)
    {
        if (!m_pMethodGen)
        {
            auto pModProf = m_pClass->AttachToModule();
            _ASSERTE(!IsNilToken(m_mdt));
            _ASSERTE(pAsmGen);
            
            if (m_functionBodyId == -1)
                FillFunctionBodyProperties(this, m_functionBodyId);
            
            auto *pILBody = reinterpret_cast<COR_ILMETHOD *>(m_functionBodyId);
            
            m_pMethodGen = pAsmGen->GetModifiableMethod(m_mdt, pILBody);
        }
        return m_pMethodGen;
    }
    
    
    
    template<class ApiHolder>    
    typename BaseFunctionProfilerPimpl<ApiHolder>::method_generator_label_type const *BaseFunctionProfilerPimpl<ApiHolder>::GetMethodGenerator(assembly_generator_label_type const *pAsmGen) const
    {
        return const_cast<class_pimpl_type *>(this)->GetMethodGenerator(const_cast<assembly_generator_label_type *>(pAsmGen));
    }



    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseFunctionProfilerPimpl<ApiHolder>::AttachToFunctionBody()
    {
        if (m_functionBodyId == -1)
            FillFunctionBodyProperties(this, m_functionBodyId);
        return m_pProcProf->AttachToFunctionBody(GetID(), m_functionBodyId);
    }



    template<class ApiHolder>    
    TempPtr<typename BaseFunctionProfilerPimpl<ApiHolder>::function_body_profiler_label_type> BaseFunctionProfilerPimpl<ApiHolder>::NewFunctionBody()
    {
        return m_pProcProf->AttachToFunctionBody(GetID(), -1);
    }



    template<class ApiHolder>    
    void BaseFunctionProfilerPimpl<ApiHolder>::SetFunctionBody(TempPtr<function_body_profiler_label_type const> const &pBodyProf)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto pModProf = m_pClass->AttachToModule();
        auto pAsmProf = pModProf->AttachToAssembly();
        auto pDomainProf = pAsmProf->AttachToAppDomain();
        auto *pDisp = pDomainProf->GetMetadataDispenser();
        auto *pAsmGen = pAsmProf->GetAssemblyGenerator(pDisp);
        
        auto pFuncProf = pBodyProf->AttachToFunction();
        auto const *pMethodGen = pFuncProf->GetMethodGenerator(pAsmGen);
        auto const *pBody = pBodyProf->GetMethodBodyGenerator(pMethodGen);
        
        auto const &header = pBody->GetRawHeader();
        auto const &body = pBody->GetRawBody();
        auto const &ehClauses = pBody->GetRawEHClauses();
        auto moreSections = !ehClauses.empty();
        auto codeSize = body.size();
        auto codeSizeAligned = codeSize;
        if (moreSections)
            codeSizeAligned = (codeSizeAligned + 3) & ~3;
        auto headerSize = COR_ILMETHOD::Size(&header, moreSections);
        auto ehSize = ehClauses.empty() ? 0 : COR_ILMETHOD_SECT_EH::Size(static_cast<UINT>(ehClauses.size()), &ehClauses[0]);
        auto totalSize = headerSize + codeSizeAligned + ehSize;
        CPPANONYM_D_LOGW1(L"Header IsFat?: %|1$d|", (headerSize != 1));
        CPPANONYM_D_LOGW1(L"Header Size: %|1$d|", headerSize);
        CPPANONYM_D_LOGW1(L"EH Clauses Count: %|1$d|", ehClauses.size());
        CPPANONYM_D_LOGW1(L"More Sections: %|1$d|", moreSections);
        CPPANONYM_D_LOGW1(L"EH Clauses Size: %|1$d|", ehSize);
        CPPANONYM_D_LOGW1(L"Local Variable Token: 0x%|1$08X|", header.GetLocalVarSigTok());
        CPPANONYM_D_LOGW1(L"Method Body Total Size: %|1$d|", totalSize);


        auto &comMethodMalloc = pAsmProf->GetCOMMethodMalloc();
        
        auto *pILBody = reinterpret_cast<BYTE *>(comMethodMalloc.Alloc(static_cast<ULONG>(totalSize)));
        auto *pBuffer = pILBody;
        pBuffer += COR_ILMETHOD::Emit(headerSize, &header, moreSections, pBuffer);
        
        ::ZeroMemory(pBuffer, codeSizeAligned);
        ::memcpy_s(pBuffer, totalSize - headerSize, &body[0], body.size());
        pBuffer += codeSizeAligned;
        
        if (!ehClauses.empty())
            pBuffer += COR_ILMETHOD_SECT_EH::Emit(ehSize, static_cast<UINT>(ehClauses.size()), &ehClauses[0], false, pBuffer);
        
        
        auto &comProfInfo = m_pProcProf->GetCOMProfilerInfo();
        _ASSERTE(m_moduleId != -1);
        _ASSERTE(m_mdt != -1);
        auto hr = comProfInfo.SetILFunctionBody(m_moduleId, m_mdt, pILBody);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
    }



    template<class ApiHolder>    
    void BaseFunctionProfilerPimpl<ApiHolder>::SetID(UINT_PTR id)
    {
        _ASSERTE(id != -1);
        _ASSERTE(m_id == -1);
        m_id = id;
    }



    template<class ApiHolder>    
    mdToken BaseFunctionProfilerPimpl<ApiHolder>::GetToken() const
    {
        if (IsNilToken(m_mdt))
            FillProperties(this, m_classId, m_moduleId, m_mdt);
        return m_mdt;
    }



    template<class ApiHolder>    
    void BaseFunctionProfilerPimpl<ApiHolder>::FillProperties(function_profiler_pimpl_label_type const *_this, ClassID &classId, ModuleID &moduleId, mdToken &mdt)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comProfInfo = _this->m_pProcProf->GetCOMProfilerInfo();

        auto functionId = _this->GetID();
        auto _classId = ClassID();
        auto _moduleId = ModuleID();
        auto _mdt = mdTokenNil;
        auto hr = comProfInfo.GetFunctionInfo(functionId, &_classId, &_moduleId, &_mdt);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));

        classId = _classId;
        moduleId = _moduleId;
        mdt = _mdt;
    }



    template<class ApiHolder>    
    void BaseFunctionProfilerPimpl<ApiHolder>::FillFunctionBodyProperties(function_profiler_pimpl_label_type const *_this, FunctionBodyID &functionBodyId)
    {
        using Urasandesu::CppAnonym::CppAnonymCOMException;

        auto &comProfInfo = _this->m_pProcProf->GetCOMProfilerInfo();
        
        auto pModProf = const_cast<function_profiler_pimpl_label_type *>(_this)->AttachToModule();

        auto mdtTarget = _this->GetToken();
        auto moduleId = pModProf->GetID();
        auto const *pILBody = LPCBYTE();
        auto ilBodySize = 0ul;
        auto hr = comProfInfo.GetILFunctionBody(moduleId, mdtTarget, &pILBody, &ilBodySize);
        if (FAILED(hr))
            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
        
        functionBodyId = reinterpret_cast<FunctionBodyID>(pILBody);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEFUNCTIONPROFILERPIMPL_HPP

