﻿/* 
 * File: NewAssemblyNameFlags.h
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
#ifndef URASANDESU_SWATHE_FUSION_NEWASSEMBLYNAMEFLAGS_H
#define URASANDESU_SWATHE_FUSION_NEWASSEMBLYNAMEFLAGS_H

namespace Urasandesu { namespace Swathe { namespace Fusion {

    namespace NewAssemblyNameFlagsDetail {

        struct NewAssemblyNameFlagsDef
        {
            enum type
            {
                NANF_CANOF_PARSE_DISPLAY_NAME = CANOF_PARSE_DISPLAY_NAME, 
                NANF_CANOF_SET_DEFAULT_VALUES = CANOF_SET_DEFAULT_VALUES, 
                NANF_CANOF_VERIFY_FRIEND_ASSEMBLYNAME = CANOF_VERIFY_FRIEND_ASSEMBLYNAME, 
                NANF_CANOF_PARSE_FRIEND_DISPLAY_NAME = CANOF_PARSE_FRIEND_DISPLAY_NAME, 
                NANF_UNREACHED
            };
        };

    }   // NewAssemblyNameFlagsDetail

    typedef Urasandesu::CppAnonym::SafeEnum<NewAssemblyNameFlagsDetail::NewAssemblyNameFlagsDef> NewAssemblyNameFlags;

}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_NEWASSEMBLYNAMEFLAGS_H
