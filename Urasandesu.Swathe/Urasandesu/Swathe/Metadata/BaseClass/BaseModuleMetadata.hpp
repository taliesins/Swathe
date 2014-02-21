﻿/* 
 * File: BaseModuleMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseModuleMetadata<ApiHolder>::BaseModuleMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(module_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(module_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())module_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseModuleMetadata<ApiHolder>::~BaseModuleMetadata()
    {
        Pimpl()->~module_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseModuleMetadata<ApiHolder>::module_metadata_pimpl_label_type *BaseModuleMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<module_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseModuleMetadata<ApiHolder>::module_metadata_pimpl_label_type const *BaseModuleMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_MODULE_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    
    template<class ApiHolder>    
    void BaseModuleMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdModule BaseModuleMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }
    
    template<class ApiHolder>    
    wstring const &BaseModuleMetadata<ApiHolder>::GetName() const
    {
        return Pimpl()->GetName();
    }
    
    template<class ApiHolder>    
    IType const *BaseModuleMetadata<ApiHolder>::GetType(wstring const &fullName) const
    {
        return Pimpl()->GetType(fullName);
    }

    template<class ApiHolder>    
    vector<IType const *> const &BaseModuleMetadata<ApiHolder>::GetTypes() const
    {
        return Pimpl()->GetTypes();
    }

    template<class ApiHolder>    
    IAssembly const *BaseModuleMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }
    
    template<class ApiHolder>    
    IModule const *BaseModuleMetadata<ApiHolder>::GetSourceModule() const
    {
        return Pimpl()->GetSourceModule();
    }

    template<class ApiHolder>    
    void BaseModuleMetadata<ApiHolder>::SetName(wstring const &name)
    {
        Pimpl()->SetName(name);
    }

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEMETADATA_HPP

