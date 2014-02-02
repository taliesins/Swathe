﻿/* 
 * File: ITypeHash.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_ITYPEHASH_H
#include <Urasandesu/Swathe/Metadata/ITypeHash.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLYHASH_H
#include <Urasandesu/Swathe/Metadata/IAssemblyHash.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace ITypeHashDetail {
        
        using Urasandesu::CppAnonym::Collections::SequenceHashValue;

        ITypeHashImpl::result_type ITypeHashImpl::operator()(param_type v) const
        {
            if (!v)
                return 0;
            
            auto isGenericDefinition = !v->IsGenericType() || v->IsGenericTypeDefinition();
            auto mdtTarget = v->GetToken();
            auto isByRef = static_cast<INT>(v->IsByRef());
            auto isArray = static_cast<INT>(v->IsArray());
            auto const *pAsm = v->GetAssembly();
            return isGenericDefinition ? 
                        (mdtTarget ^ isByRef ^ isArray ^ IAssemblyHash()(pAsm)) : 
                        (mdtTarget ^ isByRef ^ isArray ^ IAssemblyHash()(pAsm) ^ HashValue(v->GetGenericArguments()));
        }

        ITypeHashImpl::result_type ITypeHashImpl::HashValue(vector<IType const *> const &v)
        {
            return SequenceHashValue(v.begin(), v.end());
        }

    }   // namespace ITypeHashDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
