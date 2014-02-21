﻿/* 
 * File: BaseTypeGeneratorPimpl.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_H
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseTypeGeneratorPimpl.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETADATAVISITOR_H
#include <Urasandesu/Swathe/Metadata/IMetadataVisitor.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

    template<class ApiHolder>    
    BaseTypeGeneratorPimpl<ApiHolder>::BaseTypeGeneratorPimpl(type_generator_label_type *pClass) : 
        m_pClass(pClass), 
        m_pAsmGen(nullptr), 
        m_moduleInit(false), 
        m_declaringTypeInit(false), 
        m_declaringMethodInit(false), 
        m_mdt(mdTokenNil), 
        m_attr(TypeAttributes::TA_UNREACHED), 
        m_genericParamPos(static_cast<ULONG>(-1)), 
        m_genericArgsInit(false), 
        m_interfacesInit(false), 
        m_kind(TypeKinds::TK_UNREACHED), 
        m_baseTypeInit(false),
        m_pBaseType(nullptr), 
        m_pSrcType(nullptr)
    { }
    
#define SWATHE_DECLARE_BASE_TYPE_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::Initialize(assembly_generator_label_type *pAsmGen)
    {
        _ASSERTE(pAsmGen);
        _ASSERTE(!m_pAsmGen);
        m_pAsmGen = pAsmGen;
    }



    template<class ApiHolder>    
    mdToken BaseTypeGeneratorPimpl<ApiHolder>::GetToken() const
    {
        BOOST_LOG_FUNCTION();

        using Urasandesu::CppAnonym::CppAnonymCOMException;

        if (IsNilToken(m_mdt))
        {
            BOOST_LOG_NAMED_SCOPE("if (IsNilToken(m_mdt))");

            if (!m_pSrcType)
            {
                BOOST_LOG_NAMED_SCOPE("if (!m_pSrcType)");

                auto const *pDeclaringType = GetDeclaringType();
                if (!pDeclaringType)
                {
                    BOOST_LOG_NAMED_SCOPE("if (!pDeclaringType)");

                    auto const &fullName = GetFullName();
                    CPPANONYM_D_LOGW1(L"Getting Type Generator Token... 1: %|1$s|", fullName);
                    auto attr = GetAttribute();
                    auto mdExtends = GetBaseType()->GetToken();
                    auto const &interfaces = GetInterfaces();
                    auto mdImplements = vector<mdToken>();
                    mdImplements.reserve(interfaces.size() + 1);
                    for (auto i = interfaces.begin(), i_end = interfaces.end(); i != i_end; ++i)
                        mdImplements.push_back((*i)->GetToken());
                    mdImplements.push_back(mdTokenNil);
                    auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                    auto hr = comMetaEmt.DefineTypeDef(fullName.c_str(), attr.Value(), mdExtends, &mdImplements[0], &m_mdt);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
                else
                {
                    BOOST_LOG_NAMED_SCOPE("if (pDeclaringType)");

                    auto const &fullName = GetFullName();
                    CPPANONYM_D_LOGW1(L"Getting Type Generator Token... 4: %|1$s|", fullName);
                    auto attr = GetAttribute();
                    auto mdExtends = GetBaseType()->GetToken();
                    auto const &interfaces = GetInterfaces();
                    auto mdImplements = vector<mdToken>();
                    mdImplements.reserve(interfaces.size() + 1);
                    for (auto i = interfaces.begin(), i_end = interfaces.end(); i != i_end; ++i)
                        mdImplements.push_back((*i)->GetToken());
                    mdImplements.push_back(mdTokenNil);
                    auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                    auto hr = comMetaEmt.DefineNestedType(fullName.c_str(), attr.Value(), mdExtends, &mdImplements[0], pDeclaringType->GetToken(), &m_mdt);
                    if (FAILED(hr))
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                }
            }
            else
            {
                BOOST_LOG_NAMED_SCOPE("if (m_pSrcType)");

                if (!m_pAsmGen->IsModifiable())
                {
                    BOOST_LOG_NAMED_SCOPE("if (!m_pAsmGen->IsModifiable())");

                    auto isGenericTypeInstance = IsGenericType() && !IsGenericTypeDefinition();
                    if (isGenericTypeInstance)
                    {
                        BOOST_LOG_NAMED_SCOPE("if (isGenericTypeInstance)");

                        CPPANONYM_D_LOGW(L"Getting Type Generator Token... 2: Generic Type Instance");
                        auto const &sig = m_pClass->GetSignature();
                        auto const &blob = sig.GetBlob();
                        if (CPPANONYM_D_LOG_ENABLED())
                        {
                            auto oss = std::wostringstream();
                            oss << L"Signature:";
                            for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
                                oss << boost::wformat(L" %|1$02X|") % static_cast<INT>(*i);
                            CPPANONYM_D_LOGW(oss.str());
                        }
                        auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                        auto hr = comMetaEmt.GetTokenFromTypeSpec(&blob[0], blob.size(), &m_mdt);
                        if (FAILED(hr))
                            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                    }
                    else
                    {
                        BOOST_LOG_NAMED_SCOPE("if (!isGenericTypeInstance)");

                        auto mdResolutionScope = m_pAsmGen->GetToken();
                        auto const &fullName = m_pSrcType->GetFullName();
                        CPPANONYM_D_LOGW1(L"Getting Type Generator Token... 3: %|1$s|", fullName);
                        auto &comMetaEmt = m_pAsmGen->GetCOMMetaDataEmit();
                        auto hr = comMetaEmt.DefineTypeRefByName(mdResolutionScope, fullName.c_str(), &m_mdt);
                        if (FAILED(hr))
                            BOOST_THROW_EXCEPTION(CppAnonymCOMException(hr));
                    }
                }
                else
                {
                    BOOST_LOG_NAMED_SCOPE("if (m_pAsmGen->IsModifiable())");
                    CPPANONYM_D_LOGW(L"Getting Type Generator Token... 4: Modifiable Type");
                    m_mdt = m_pSrcType->GetToken();
                }
            }
            CPPANONYM_D_LOGW1(L"Token: 0x%|1$08X|", m_mdt);
        }
        return m_mdt;
    }



    template<class ApiHolder>    
    wstring const &BaseTypeGeneratorPimpl<ApiHolder>::GetFullName() const
    {
        if (m_fullName.empty())
        {
            if (m_pSrcType == nullptr)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_fullName = m_pSrcType->GetFullName();
            }
        }
        return m_fullName;
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsValueType() const
    {
        if (!m_pSrcType)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcType->IsValueType();
        }
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsGenericParameter() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsGenericType() const
    {
        return !GetGenericArguments().empty();
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsGenericTypeDefinition() const
    {
        if (m_pSrcType == nullptr)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //if (!IsGenericType())
            //{
            //    return false;
            //}
            //else
            //{
            //    return !m_pDeclaringType;
            //}
        }
        else
        {
            return m_pSrcType->IsGenericTypeDefinition();
        }
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsByRef() const
    {
        if (!m_pSrcType)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pSrcType->IsByRef();
        }
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsArray() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ULONG BaseTypeGeneratorPimpl<ApiHolder>::GetGenericParameterPosition() const
    {
        if (m_genericParamPos == static_cast<ULONG>(-1))
        {
            if (!m_pSrcType)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_genericParamPos = m_pSrcType->GetGenericParameterPosition();
            }
        }
        return m_genericParamPos;
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeGeneratorPimpl<ApiHolder>::GetGenericArguments() const
    {
        if (!m_genericArgsInit)
        {
            if (!m_pSrcType)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                auto const &genericArgs = m_pSrcType->GetGenericArguments();
                for (auto i = genericArgs.begin(), i_end = genericArgs.end(); i != i_end; ++i)
                    m_genericArgs.push_back(m_pAsmGen->Resolve(*i));
            }
            m_genericArgsInit = true;
        }
        return m_genericArgs;
    }



    template<class ApiHolder>    
    Signature const &BaseTypeGeneratorPimpl<ApiHolder>::GetSignature() const
    {
        if (m_sig.GetBlob().empty())
            m_sig.Encode(m_pClass);
        _ASSERTE(!m_sig.GetBlob().empty());
        return m_sig;
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::MakeArrayType() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::MakeGenericType(vector<IType const *> const &genericArgs) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::MakePointerType() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::MakeByRefType() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::MakePinnedType() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeGeneratorPimpl<ApiHolder>::GetMethod(wstring const &name) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeGeneratorPimpl<ApiHolder>::GetMethod(wstring const &name, vector<IType const *> const &paramTypes) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeGeneratorPimpl<ApiHolder>::GetMethod(wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeGeneratorPimpl<ApiHolder>::GetConstructor(vector<IType const *> const &paramTypes) const
    {
        if (!m_pSrcType)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            return m_pAsmGen->Resolve(m_pSrcType->GetConstructor(paramTypes));
        }
    }



    template<class ApiHolder>    
    IProperty const *BaseTypeGeneratorPimpl<ApiHolder>::GetProperty(wstring const &name) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethodPtrRange BaseTypeGeneratorPimpl<ApiHolder>::GetMethods() const
    {
        using boost::adaptors::transformed;
        using std::function;

        typedef vector<pair<method_generator_label_type const *, SIZE_T> > MethodGenToIndex;
        typedef MethodGenToIndex::value_type Value;

        if (!m_pSrcType)
        {
            auto const &methodGenToIndex = m_pAsmGen->GetMethodGeneratorToIndex();
            auto isMine = [&](Value const &v) { return v.first->GetDeclaringType() == m_pClass; };
            auto toUpper = function<IMethod const *(Value const &)>();
            toUpper = [](Value const &v) { return static_cast<IMethod const *>(v.first); };
            return methodGenToIndex | transformed(toUpper);
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
    }



    template<class ApiHolder>    
    IMethodPtrRange BaseTypeGeneratorPimpl<ApiHolder>::GetConstructors() const
    {
        using boost::adaptors::filtered;
        using boost::empty;
        using std::function;
        
        if (!m_pSrcType)
        {
            auto isCtor = function<bool (IMethod const *)>();
            isCtor = [](IMethod const *pMethod) { return pMethod->GetName() == MetadataSpecialValues::METHOD_NAME_OF_CTOR; };
            auto ctors = m_pClass->GetMethods() | filtered(isCtor);
            if (empty(ctors))
            {
                auto const *pBaseType = m_pClass->GetBaseType();
                auto const *pBaseType_ctor = pBaseType->GetConstructor(MetadataSpecialValues::EMPTY_TYPES);
                auto *pTypeGen_ctor = m_pClass->DefineDefaultConstructor(MethodAttributes::MA_PUBLIC | 
                                                                         MethodAttributes::MA_HIDE_BY_SIG | 
                                                                         MethodAttributes::MA_SPECIAL_NAME);
                {
                    auto *pBodyGen = pTypeGen_ctor->DefineMethodBody();
                    pBodyGen->Emit(OpCodes::Ldarg_0);
                    pBodyGen->Emit(OpCodes::Call, pBaseType_ctor);
                    pBodyGen->Emit(OpCodes::Ret);
                }
                
                ctors = m_pClass->GetMethods() | filtered(isCtor);
            }
            return ctors;
        }
        else
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
    }



    template<class ApiHolder>    
    vector<IProperty const *> const &BaseTypeGeneratorPimpl<ApiHolder>::GetProperties() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    TypeKinds BaseTypeGeneratorPimpl<ApiHolder>::GetKind() const
    {
        if (m_kind == TypeKinds::TK_UNREACHED)
        {
            if (!m_pSrcType)
            {
                auto const &fullName = GetFullName();
                if (m_kind == TypeKinds::TK_UNREACHED)
                {
                    m_kind = MetadataSpecialValues::ToTypeKind(fullName);
                    if (m_kind == TypeKinds::TK_UNREACHED)
                    {
                        auto const &baseTypeFullName = GetBaseType()->GetFullName();
                        m_kind = MetadataSpecialValues::ToTypeKind(fullName, baseTypeFullName);
                    }
                }
            }
            else
            {
                m_kind = m_pSrcType->GetKind();
            }
        }
        return m_kind;
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::GetGenericTypeDefinition() const
    {
        return GetDeclaringType();
        //if (m_pSrcType == nullptr)
        //{
        //    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //}
        //else
        //{
        //    auto isGenericTypeInstance = m_pSrcType->IsGenericType() && !m_pSrcType->IsGenericTypeDefinition();
        //    if (isGenericTypeInstance)
        //    {
        //        auto const *pDeclaringTypeGen = m_pSrcType->GetDeclaringType(); // TODO: キャッシュ必要。
        //        _ASSERTE(pDeclaringTypeGen != nullptr);
        //        return MetadataResolver::Resolve(pDeclaringTypeGen);
        //    }
        //    else
        //    {
        //        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        //    }
        //}
    }



    template<class ApiHolder>    
    TypeAttributes BaseTypeGeneratorPimpl<ApiHolder>::GetAttribute() const
    {
        if (m_attr == TypeAttributes::TA_UNREACHED)
        {
            if (!m_pSrcType)
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            else
            {
                m_attr = m_pSrcType->GetAttribute();
            }
        }
        return m_attr;
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::GetBaseType() const
    {
        if (!m_baseTypeInit)
        {
            if (m_pBaseType == nullptr)
            {
                if (m_pSrcType == nullptr)
                {
                    auto const &refAsms = m_pAsmGen->GetReferencedAssemblies();
                    auto const *pMSCorLib = refAsms[0];
                    auto const *pMSCorLibDll = pMSCorLib->GetMainModule();
                    m_pBaseType = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_OBJECT);
                }
                else
                {
                    m_pBaseType = m_pAsmGen->Resolve(m_pSrcType->GetBaseType());
                }
            }
            else
            {
                m_pBaseType = m_pAsmGen->Resolve(m_pBaseType);
            }
            m_baseTypeInit = true;
        }
        return m_pBaseType;
    }



    template<class ApiHolder>    
    vector<IType const *> const &BaseTypeGeneratorPimpl<ApiHolder>::GetInterfaces() const
    {
        if (!m_interfacesInit)
        {
            if (m_pSrcType == nullptr)
            {
                if (m_interfaces.empty())
                {
                    // nop
                }
                else
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
            }
            else
            {
                auto const &interfaces = m_pSrcType->GetInterfaces();
                for (auto i = interfaces.begin(), i_end = interfaces.end(); i != i_end; ++i)
                    m_interfaces.push_back(m_pAsmGen->Resolve(*i));
            }
            m_interfacesInit = true;
        }
        return m_interfaces;
    }




    template<class ApiHolder>    
    IModule const *BaseTypeGeneratorPimpl<ApiHolder>::GetModule() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_moduleInit)
        {
            if (Empty(m_member))
            {
                _ASSERTE(m_pSrcType);
                auto const *pMod = m_pSrcType->GetModule();
                if (pMod)
                    m_member = m_pAsmGen->Resolve(pMod);
            }

            m_moduleInit = true;
        }

        auto const *const *ppMod = get<IModule const *>(&m_member);
        return !ppMod ? nullptr : *ppMod;
    }




    template<class ApiHolder>    
    IAssembly const *BaseTypeGeneratorPimpl<ApiHolder>::GetAssembly() const
    {
        return m_pAsmGen;
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::GetDeclaringType() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_declaringTypeInit)
        {
            if (Empty(m_member))
            {
                _ASSERTE(m_pSrcType);
                auto const *pDeclaringType = m_pSrcType->GetDeclaringType();
                if (pDeclaringType)
                    m_member = m_pAsmGen->Resolve(pDeclaringType);
            }

            m_declaringTypeInit = true;
        }

        auto const *const *ppDeclaringType = get<IType const *>(&m_member);
        return !ppDeclaringType ? nullptr : *ppDeclaringType;
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeGeneratorPimpl<ApiHolder>::GetDeclaringMethod() const
    {
        using boost::get;
        using Urasandesu::CppAnonym::Utilities::Empty;

        if (!m_declaringMethodInit)
        {
            if (Empty(m_member))
            {
                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            }
            
            m_declaringMethodInit = true;
        }

        auto const *const *ppDeclaringMethod = get<IMethod const *>(&m_member);
        return !ppDeclaringMethod ? nullptr : *ppDeclaringMethod;
    }



    template<class ApiHolder>    
    TypeProvider const &BaseTypeGeneratorPimpl<ApiHolder>::GetMember() const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IMethod const *BaseTypeGeneratorPimpl<ApiHolder>::GetMethod(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IProperty const *BaseTypeGeneratorPimpl<ApiHolder>::GetProperty(mdToken mdt) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    bool BaseTypeGeneratorPimpl<ApiHolder>::IsDefined(IType const *pAttrType, bool inherit) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeGeneratorPimpl<ApiHolder>::GetCustomAttributes(bool inherit) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    ICustomAttributePtrRange BaseTypeGeneratorPimpl<ApiHolder>::GetCustomAttributes(IType const *pAttributeType, bool inherit) const
    {
        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    }



    template<class ApiHolder>    
    IType const *BaseTypeGeneratorPimpl<ApiHolder>::GetSourceType() const
    {
        return m_pSrcType == nullptr ? m_pClass : m_pSrcType->GetSourceType();
    }



    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::OutDebugInfo() const
    {
        if (!m_pSrcType)
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
        }
        else
        {
            m_pSrcType->OutDebugInfo();
        }
    }



    template<class ApiHolder>    
    typename BaseTypeGeneratorPimpl<ApiHolder>::type_generator_label_type *BaseTypeGeneratorPimpl<ApiHolder>::DefineNestedType(wstring const &fullName, TypeAttributes const &attr)
    {
        return m_pAsmGen->DefineType(fullName, attr, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    typename BaseTypeGeneratorPimpl<ApiHolder>::field_generator_label_type *BaseTypeGeneratorPimpl<ApiHolder>::DefineField(wstring const &name, IType const *pFieldType, FieldAttributes const &attr)
    {
        return m_pAsmGen->DefineField(name, pFieldType, attr, static_cast<IType const *>(m_pClass));
    }



    template<class ApiHolder>    
    typename BaseTypeGeneratorPimpl<ApiHolder>::method_generator_label_type *BaseTypeGeneratorPimpl<ApiHolder>::DefineMethod(wstring const &name, MethodAttributes const &attr, CallingConventions const &callingConvention, IType const *pRetType, vector<IType const *> const &paramTypes)
    {
        auto *pMethodGen = m_pAsmGen->DefineMethod(name, attr, callingConvention, pRetType, false, MetadataSpecialValues::EMPTY_PARAMETERS, static_cast<IType const *>(m_pClass));
        for (auto i = 0ul; i < paramTypes.size(); ++i)
            pMethodGen->DefineParameter(i + 1ul, paramTypes[i]);
        return pMethodGen;
    }



    template<class ApiHolder>    
    typename BaseTypeGeneratorPimpl<ApiHolder>::method_generator_label_type *BaseTypeGeneratorPimpl<ApiHolder>::DefineDefaultConstructor(MethodAttributes const &attr)
    {
        auto const &refAsms = m_pAsmGen->GetReferencedAssemblies();
        auto const *pMSCorLib = refAsms[0];
        auto const *pMSCorLibDll = pMSCorLib->GetMainModule();
        auto const *pVoid = pMSCorLibDll->GetType(MetadataSpecialValues::TYPE_NAME_OF_VOID);
        return m_pClass->DefineMethod(MetadataSpecialValues::METHOD_NAME_OF_CTOR, attr, CallingConventions::CC_HAS_THIS, pVoid, MetadataSpecialValues::EMPTY_TYPES);
    }



    template<class ApiHolder>    
    typename BaseTypeGeneratorPimpl<ApiHolder>::property_generator_label_type *BaseTypeGeneratorPimpl<ApiHolder>::DefineProperty(wstring const &name, PropertyAttributes const &attr, IType const *pPropType, vector<IType const *> const &paramTypes)
    {
        auto *pPropGen = m_pAsmGen->DefineProperty(name, attr, pPropType, false, MetadataSpecialValues::EMPTY_PARAMETERS, static_cast<IType const *>(m_pClass));
        for (auto i = 0ul; i < paramTypes.size(); ++i)
            pPropGen->DefineParameter(i, paramTypes[i]);
        return pPropGen;
    }



    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::SetFullName(wstring const &fullName)
    {
        _ASSERTE(!fullName.empty());
        _ASSERTE(m_fullName.empty());
        m_fullName = fullName;
    }



    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::SetAttributes(TypeAttributes const &attr)
    {
        _ASSERTE(attr != TypeAttributes::TA_UNREACHED);
        _ASSERTE(m_attr == TypeAttributes::TA_UNREACHED);
        m_attr = attr;
    }



    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::SetMember(TypeProvider const &member)
    {
        using Urasandesu::CppAnonym::Utilities::Empty;

        _ASSERTE(Empty(m_member));
        m_member = member;
    }



    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::SetSourceType(IType const *pSrcType)
    {
        _ASSERTE(pSrcType != nullptr);
        _ASSERTE(m_pSrcType == nullptr);
        m_pSrcType = pSrcType;
    }



    template<class ApiHolder>    
    void BaseTypeGeneratorPimpl<ApiHolder>::Accept(IMetadataVisitor *pVisitor) const
    {
        pVisitor->Visit(m_pClass);

        // TODO: Type 向けのデフォルト Custom Attribute を実装。
        //m_pClass->GetCustomAttributes(false);   // resolves default custom attributes of this Assembly.
        //for (auto i = m_caGenToIndex.begin(), i_end = m_caGenToIndex.end(); i != i_end; ++i)
        //    (*i).first->Accept(pVisitor);

        auto const &typeGenToIndex = m_pAsmGen->GetTypeGeneratorToIndex();
        for (auto i = 0ul; i < typeGenToIndex.size(); ++i)
            if (typeGenToIndex[i].first->GetDeclaringType() == m_pClass)
                typeGenToIndex[i].first->Accept(pVisitor);

        auto const &fieldGenToIndex = m_pAsmGen->GetFieldGeneratorToIndex();
        for (auto i = 0ul; i < fieldGenToIndex.size(); ++i)
            if (fieldGenToIndex[i].first->GetDeclaringType() == m_pClass)
                fieldGenToIndex[i].first->Accept(pVisitor);

        m_pClass->GetConstructors();
        auto const &methodGenToIndex = m_pAsmGen->GetMethodGeneratorToIndex();
        for (auto i = 0ul; i < methodGenToIndex.size(); ++i)
            if (methodGenToIndex[i].first->GetDeclaringType() == m_pClass)
                methodGenToIndex[i].first->Accept(pVisitor);

        auto const &propGenToIndex = m_pAsmGen->GetPropertyGeneratorToIndex();
        for (auto i = 0ul; i < propGenToIndex.size(); ++i)
            if (propGenToIndex[i].first->GetDeclaringType() == m_pClass)
                propGenToIndex[i].first->Accept(pVisitor);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASETYPEGENERATORPIMPL_HPP

