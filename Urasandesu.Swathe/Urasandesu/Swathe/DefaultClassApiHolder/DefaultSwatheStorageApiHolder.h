﻿/* 
 * File: DefaultSwatheStorageApiHolder.h
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
#ifndef URASANDESU_SWATHE_DEFAULTCLASSAPIHOLDER_DEFAULTSWATHESTORAGEAPIHOLDER_H
#define URASANDESU_SWATHE_DEFAULTCLASSAPIHOLDER_DEFAULTSWATHESTORAGEAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_HOSTINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/HostInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_HOSTINFOFWD_H
#include <Urasandesu/Swathe/Hosting/HostInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_DEFAULTCLASSAPIHOLDER_DEFAULTSWATHESTORAGEAPIHOLDERFWD_H
#include <Urasandesu/Swathe/DefaultClassApiHolder/DefaultSwatheStorageApiHolderFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace DefaultClassApiHolder {
    
    namespace DefaultSwatheStorageApiHolderDetail {

        namespace mpl = boost::mpl;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::HostInfoLabel;
        using Urasandesu::Swathe::Hosting::HostInfo;
        using mpl::map;
        using mpl::pair;

        struct DefaultSwatheStorageApiHolderImpl
        {
            typedef map<
                pair<HostInfoLabel, HostInfo>
            > api_cartridges;
        };

    }   // namespace DefaultSwatheStorageApiHolderDetail {

    struct DefaultSwatheStorageApiHolder : 
        DefaultSwatheStorageApiHolderDetail::DefaultSwatheStorageApiHolderImpl
    {
    };
        
}}}  // namespace Urasandesu { namespace Swathe { namespace DefaultClassApiHolder {

#endif  // URASANDESU_SWATHE_DEFAULTCLASSAPIHOLDER_DEFAULTSWATHESTORAGEAPIHOLDER_H
