﻿/* 
 * File: DefaultLocalGeneratorPimplApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTLOCALGENERATORPIMPLAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTLOCALGENERATORPIMPLAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_LOCALGENERATORPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/LocalGeneratorPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyGeneratorFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassPimplApiHolder { 

    namespace DefaultLocalGeneratorPimplApiHolderDetail {

        namespace mpl = boost::mpl;
        using Urasandesu::Swathe::AutoGen::Metadata::DefaultClassApiHolder::DefaultLocalGeneratorApiHolder;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::LocalGeneratorPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::Metadata::AssemblyGenerator;
        using mpl::_1;
        using mpl::_2;
        using mpl::fold;
        using mpl::insert;
        using mpl::map;
        using mpl::pair;

        struct DefaultLocalGeneratorPimplApiHolderImpl : 
            DefaultLocalGeneratorApiHolder
        {
            typedef map<
                pair<LocalGeneratorPersistedHandlerLabel, LocalGeneratorPersistedHandler>,
                pair<AssemblyGeneratorLabel, AssemblyGenerator>
            > additional_api_cartridges;

            typedef fold<
                additional_api_cartridges,
                DefaultLocalGeneratorApiHolder::api_cartridges,
                insert<_1, _2>
            >::type api_cartridges;
        };

    }   // namespace DefaultLocalGeneratorPimplApiHolderDetail {

    struct DefaultLocalGeneratorPimplApiHolder : 
        DefaultLocalGeneratorPimplApiHolderDetail::DefaultLocalGeneratorPimplApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassPimplApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTLOCALGENERATORPIMPLAPIHOLDER_H

