﻿/* 
 * File: BaseAssemblyProfilerPimpl.h
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
#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_H
#define URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_CLASSPIMPLFACADE_ASSEMBLYPROFILERPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Profiling/ClassPimplFacade/AssemblyProfilerPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPLFWD_H
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseAssemblyProfilerPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

    using boost::aligned_storage;
    using std::wstring;
    using Urasandesu::CppAnonym::Utilities::TempPtr;
    
    template<
        class ApiHolder
    >    
    class BaseAssemblyProfilerPimpl
    {
    public:
        SWATHE_BEGIN_ASSEMBLY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_ASSEMBLY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_ASSEMBLY_PROFILER_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseAssemblyProfilerPimpl(assembly_profiler_label_type *pClass);

        void Initialize(process_profiler_label_type *pProcProf);
        UINT_PTR GetID() const;
        wstring const &GetName() const;
        TempPtr<app_domain_profiler_label_type> AttachToAppDomain();
        assembly_generator_label_type *GetAssemblyGenerator(metadata_dispenser_label_type *pDisp);
        
    private:
        void SetID(UINT_PTR id);
        static void FillProperties(assembly_profiler_pimpl_label_type const *_this, wstring &name, AppDomainID &appDomainId, ModuleID &moduleId);
        IMethodMalloc &GetCOMMethodMalloc();

        mutable assembly_profiler_label_type *m_pClass;
        process_profiler_label_type *m_pProcProf;
        UINT_PTR m_id;
        mutable wstring m_name;
        mutable AppDomainID m_appDomainId;
        mutable ModuleID m_moduleId;
        mutable assembly_generator_label_type *m_pAsmGen;
        ATL::CComPtr<IMethodMalloc> m_pComMethodMalloc;
        int reserved;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Profiling { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEASSEMBLYPROFILERPIMPL_H

