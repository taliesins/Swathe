﻿/* 
 * File: IType.h
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
#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#define URASANDESU_SWATHE_METADATA_ITYPE_H

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/IDispenserFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_CALLINGCONVENTIONS_H
#include <Urasandesu/Swathe/Metadata/CallingConventions.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEKINDS_H
#include <Urasandesu/Swathe/Metadata/TypeKinds.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_SIGNATUREFWD_H
#include <Urasandesu/Swathe/Metadata/SignatureFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPEFWD_H
#include <Urasandesu/Swathe/Metadata/ITypeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODFWD_H
#include <Urasandesu/Swathe/Metadata/IMethodFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTYFWD_H
#include <Urasandesu/Swathe/Metadata/IPropertyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYFWD_H
#include <Urasandesu/Swathe/Metadata/IAssemblyFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELDFWD_H
#include <Urasandesu/Swathe/Metadata/IFieldFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTEFWD_H
#include <Urasandesu/Swathe/Metadata/ICustomAttributeFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEATTRIBUTES_HPP
#include <Urasandesu/Swathe/Metadata/TypeAttributes.hpp>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 

    struct IType
    {
        IType() { }
        virtual mdToken GetToken() const = 0;
        virtual std::wstring const &GetFullName() const = 0;
        virtual bool IsValueType() const = 0;
        virtual bool IsGenericParameter() const = 0;
        virtual bool IsGenericType() const = 0;
        virtual bool IsGenericTypeDefinition() const = 0;
        virtual bool IsByRef() const = 0;
        virtual bool IsArray() const = 0;
        virtual ULONG GetGenericParameterPosition() const = 0;
        virtual std::vector<IType const *> const &GetGenericArguments() const = 0;
        virtual Signature const &GetSignature() const = 0;
        virtual IType const *MakeArrayType() const = 0;
        virtual IType const *MakeGenericType(std::vector<IType const *> const &genericArgs) const = 0;
        virtual IType const *MakePointerType() const = 0;
        virtual IType const *MakeByRefType() const = 0;
        virtual IType const *MakePinnedType() const = 0;
        virtual IMethod const *GetMethod(std::wstring const &name) const = 0;
        virtual IMethod const *GetMethod(std::wstring const &name, std::vector<IType const *> const &paramTypes) const = 0;
        virtual IMethod const *GetMethod(std::wstring const &name, CallingConventions const &callingConvention, IType const *pRetType, std::vector<IType const *> const &paramTypes) const = 0;
        virtual IMethod const *GetConstructor(std::vector<IType const *> const &paramTypes) const = 0;
        virtual IProperty const *GetProperty(std::wstring const &name) const = 0;
        virtual IMethodPtrRange GetMethods() const = 0;
        virtual IMethodPtrRange GetConstructors() const = 0;
        virtual std::vector<IProperty const *> const &GetProperties() const = 0;
        virtual TypeKinds GetKind() const = 0;
        virtual IType const *GetGenericTypeDefinition() const = 0;
        virtual TypeAttributes GetAttribute() const = 0;
        virtual IType const *GetBaseType() const = 0;
        virtual std::vector<IType const *> const &GetInterfaces() const = 0;
        virtual IModule const *GetModule() const = 0;
        virtual IAssembly const *GetAssembly() const = 0;
        virtual IType const *GetDeclaringType() const = 0;
        virtual IMethod const *GetDeclaringMethod() const = 0;
        virtual TypeProvider const &GetMember() const = 0;
        virtual IMethod const *GetMethod(mdToken mdt) const = 0;
        virtual IProperty const *GetProperty(mdToken mdt) const = 0;
        virtual bool IsDefined(IType const *pAttrType, bool inherit) const = 0;
        virtual ICustomAttributePtrRange GetCustomAttributes(bool inherit) const = 0;
        virtual ICustomAttributePtrRange GetCustomAttributes(IType const *pAttributeType, bool inherit) const = 0;
        virtual IType const *GetSourceType() const = 0;
        virtual void OutDebugInfo() const = 0;
    };
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // URASANDESU_SWATHE_METADATA_ITYPE_H

