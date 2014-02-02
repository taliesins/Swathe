﻿/* 
 * File: AssemblyCacheFlags.h
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
#ifndef URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFLAGS_H
#define URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFLAGS_H

namespace Urasandesu { namespace Swathe { namespace Fusion {

    namespace AssemblyCacheFlagsDetail {

        struct AssemblyCacheFlagsDef
        {
            enum type
            {
                ACF_ZAP = ASM_CACHE_ZAP, 
                ACF_GAC = ASM_CACHE_GAC, 
                ACF_DOWNLOAD = ASM_CACHE_DOWNLOAD, 
                ACF_ROOT = ASM_CACHE_ROOT, 
                ACF_ROOT_EX = ASM_CACHE_ROOT_EX, 
                ACF_UNREACHED
            };
        };

    }   // AssemblyCacheFlagsDetail

    typedef Urasandesu::CppAnonym::SafeEnum<AssemblyCacheFlagsDetail::AssemblyCacheFlagsDef> AssemblyCacheFlags;

}}}  // namespace Urasandesu { namespace Swathe { namespace Fusion {

#endif  // URASANDESU_SWATHE_FUSION_ASSEMBLYCACHEFLAGS_H
