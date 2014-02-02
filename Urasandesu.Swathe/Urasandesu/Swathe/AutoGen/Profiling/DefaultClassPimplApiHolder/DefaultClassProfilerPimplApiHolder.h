﻿/* 
 * File: DefaultClassProfilerPimplApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTCLASSPROFILERPIMPLAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTCLASSPROFILERPIMPLAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTCLASSPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultClassProfilerApiHolder.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace DefaultClassPimplApiHolder { 

    namespace DefaultClassProfilerPimplApiHolderDetail {

        namespace mpl = boost::mpl;
        using Urasandesu::Swathe::AutoGen::Profiling::DefaultClassApiHolder::DefaultClassProfilerApiHolder;
        using mpl::_1;
        using mpl::_2;
        using mpl::fold;
        using mpl::insert;
        using mpl::map;
        using mpl::pair;

        struct DefaultClassProfilerPimplApiHolderImpl : 
            DefaultClassProfilerApiHolder
        {
            typedef map<

            > additional_api_cartridges;

            typedef fold<
                additional_api_cartridges,
                DefaultClassProfilerApiHolder::api_cartridges,
                insert<_1, _2>
            >::type api_cartridges;
        };

    }   // namespace DefaultClassProfilerPimplApiHolderDetail {

    struct DefaultClassProfilerPimplApiHolder : 
        DefaultClassProfilerPimplApiHolderDetail::DefaultClassProfilerPimplApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Profiling { namespace DefaultClassPimplApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTCLASSPROFILERPIMPLAPIHOLDER_H

