﻿/* 
 * File: BaseCustomAttributeMetadata.hpp
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_HPP
#define URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_HPP

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseCustomAttributeMetadata.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

    template<class ApiHolder>    
    BaseCustomAttributeMetadata<ApiHolder>::BaseCustomAttributeMetadata()
    {
#ifdef _DEBUG
        BOOST_MPL_ASSERT_RELATION(sizeof(custom_attribute_metadata_pimpl_label_type), <=, sizeof(storage_type));
#else
        BOOST_MPL_ASSERT_RELATION(sizeof(custom_attribute_metadata_pimpl_label_type), ==, sizeof(storage_type));
#endif
        new(Pimpl())custom_attribute_metadata_pimpl_label_type(this);
    }

    template<class ApiHolder>    
    BaseCustomAttributeMetadata<ApiHolder>::~BaseCustomAttributeMetadata()
    {
        Pimpl()->~custom_attribute_metadata_pimpl_label_type();
    }

    template<class ApiHolder>    
    typename BaseCustomAttributeMetadata<ApiHolder>::custom_attribute_metadata_pimpl_label_type *BaseCustomAttributeMetadata<ApiHolder>::Pimpl()
    {
        return reinterpret_cast<custom_attribute_metadata_pimpl_label_type *>(&m_storage);
    }

    template<class ApiHolder>    
    typename BaseCustomAttributeMetadata<ApiHolder>::custom_attribute_metadata_pimpl_label_type const *BaseCustomAttributeMetadata<ApiHolder>::Pimpl() const
    {
        return const_cast<class_type *>(this)->Pimpl();
    }
    
#define SWATHE_DECLARE_BASE_CUSTOM_ATTRIBUTE_METADATA_ADDITIONAL_INSTANTIATION \

    
    
    template<class ApiHolder>    
    void BaseCustomAttributeMetadata<ApiHolder>::Initialize(assembly_metadata_label_type *pAsm)
    {
        Pimpl()->Initialize(pAsm);
    }

    template<class ApiHolder>    
    mdToken BaseCustomAttributeMetadata<ApiHolder>::GetToken() const
    {
        return Pimpl()->GetToken();
    }

    template<class ApiHolder>    
    Signature const &BaseCustomAttributeMetadata<ApiHolder>::GetSignature() const
    {
        return Pimpl()->GetSignature();
    }

    template<class ApiHolder>    
    IMethod const *BaseCustomAttributeMetadata<ApiHolder>::GetConstructor() const
    {
        return Pimpl()->GetConstructor();
    }

    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeMetadata<ApiHolder>::GetConstructorArguments() const
    {
        return Pimpl()->GetConstructorArguments();
    }

    template<class ApiHolder>    
    vector<IProperty const *> const &BaseCustomAttributeMetadata<ApiHolder>::GetNamedProperties() const
    {
        return Pimpl()->GetNamedProperties();
    }

    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeMetadata<ApiHolder>::GetPropertyValues() const
    {
        return Pimpl()->GetPropertyValues();
    }

    template<class ApiHolder>    
    vector<IField const *> const &BaseCustomAttributeMetadata<ApiHolder>::GetNamedFields() const
    {
        return Pimpl()->GetNamedFields();
    }

    template<class ApiHolder>    
    vector<CustomAttributeArgument> const &BaseCustomAttributeMetadata<ApiHolder>::GetFieldValues() const
    {
        return Pimpl()->GetFieldValues();
    }

    template<class ApiHolder>    
    CustomAttributeProvider const &BaseCustomAttributeMetadata<ApiHolder>::GetMember() const
    {
        return Pimpl()->GetMember();
    }

    template<class ApiHolder>    
    IAssembly const *BaseCustomAttributeMetadata<ApiHolder>::GetAssembly() const
    {
        return Pimpl()->GetAssembly();
    }

    template<class ApiHolder>    
    IType const *BaseCustomAttributeMetadata<ApiHolder>::GetAttributeType() const
    {
        return Pimpl()->GetAttributeType();
    }

    template<class ApiHolder>    
    void BaseCustomAttributeMetadata<ApiHolder>::SetToken(mdToken mdt)
    {
        Pimpl()->SetToken(mdt);
    }

    template<class ApiHolder>    
    void BaseCustomAttributeMetadata<ApiHolder>::SetMember(CustomAttributeProvider const &member)
    {
        Pimpl()->SetMember(member);
    }
    
}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClass { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEMETADATA_HPP

