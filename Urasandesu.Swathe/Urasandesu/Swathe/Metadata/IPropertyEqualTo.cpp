﻿/* 
 * File: IPropertyEqualTo.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYEQUALTO_H
#include <Urasandesu/Swathe/Metadata/IPropertyEqualTo.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace IPropertyEqualToDetail {

        using Urasandesu::CppAnonym::Collections::SequenceEqual;

        IPropertyEqualToImpl::result_type IPropertyEqualToImpl::operator()(param_type x, param_type y) const
        {
            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
            //auto isXDefinition = !x->IsGenericProperty() || x->IsGenericPropertyDefinition();
            //auto isYDefinition = !y->IsGenericProperty() || y->IsGenericPropertyDefinition();

            //return (isXDefinition && isYDefinition) ? 
            //            x->GetToken() == y->GetToken() : 
            //            (isXDefinition || isYDefinition) ? 
            //                false : 
            //                (x->GetToken() == y->GetToken() && ITypeEqualTo::EqualTo(x->GetGenericArguments(), y->GetGenericArguments()));
        }

    }   // namespace IPropertyEqualToDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
