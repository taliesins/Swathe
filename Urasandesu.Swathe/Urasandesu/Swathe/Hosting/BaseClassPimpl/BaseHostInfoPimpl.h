﻿/* 
 * File: BaseHostInfoPimpl.h
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
#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_H
#define URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSPIMPLFACADE_HOSTINFOPIMPLFACADE_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassPimplFacade/HostInfoPimplFacade.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPLFWD_H
#include <Urasandesu/Swathe/Hosting/BaseClassPimpl/BaseHostInfoPimplFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;
    using boost::aligned_storage;
    using boost::unordered_map;
    using std::vector;
    using std::wstring;

    template<
        class ApiHolder
    >    
    class BaseHostInfoPimpl
    {
    public:
        SWATHE_BEGIN_HOST_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_HOST_INFO_PIMPL_FACADE_TYPEDEF_ALIAS
        SWATHE_END_HOST_INFO_PIMPL_FACADE_TYPEDEF_ALIAS

        BaseHostInfoPimpl(host_info_label_type *pClass);
        ~BaseHostInfoPimpl();

        void Initialize(host_info_label_type *pHost);
        static host_info_label_type *CreateHost();
        unordered_map<wstring, runtime_host_label_type const *> const &GetRuntimes() const;
        runtime_host_label_type const *GetRuntime(wstring const &version) const;
        
    private:
        base_heap_provider_type *BaseHeapProvider();
        base_heap_provider_type const *BaseHeapProvider() const;
        static TempPtr<host_info_label_type> NewHost();
        void RegisterHost(TempPtr<host_info_label_type> &pHost);
        TempPtr<runtime_host_label_type> NewRuntime(wstring const &version) const;
        TempPtr<runtime_host_label_type> NewRuntime(ICLRRuntimeInfo *pComRuntimeInfo) const;
        void RegisterRuntime(TempPtr<runtime_host_label_type> &pRuntime);
        bool TryGetRuntime(wstring const &version, runtime_host_label_type const *&pExistingRuntime) const;

        ICLRMetaHost &GetCOMMetaHost() const;

        static void FillRuntimes(ICLRMetaHost *pComMetaHost, host_info_pimpl_label_type const *pHostInfo, bool &versionToRuntimesInit);

#ifdef _DEBUG
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 512;
#else
#ifdef _M_IX86
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 64;
#else
        static INT const BASE_HEAP_PROVIDER_TYPE_SIZE = 128;
#endif
#endif
        typedef typename aligned_storage<BASE_HEAP_PROVIDER_TYPE_SIZE>::type storage_type;
        storage_type m_storage;
        mutable host_info_label_type *m_pClass;
        host_info_label_type *m_pHost;
        mutable vector<host_info_label_type *> m_hosts;
        mutable bool m_versionToRuntimesInit;
        mutable unordered_map<wstring, runtime_host_label_type const *> m_versionToRuntimes;
        mutable ATL::CComPtr<ICLRMetaHost> m_pComMetaHost;
    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Hosting { namespace BaseClassPimpl { 

#endif  // URASANDESU_SWATHE_HOSTING_BASECLASSPIMPL_BASEHOSTINFOPIMPL_H

