﻿/* 
 * File: DefaultPropertyMetadataPimplApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTPROPERTYMETADATAPIMPLAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTPROPERTYMETADATAPIMPLAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_PROPERTYMETADATAPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/PropertyMetadataPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_PROPERTYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/PropertyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATADISPENSERFWD_H
#include <Urasandesu/Swathe/Metadata/MetadataDispenserFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassPimplApiHolder { 

    namespace DefaultPropertyMetadataPimplApiHolderDetail {

        namespace mpl = boost::mpl;
        using Urasandesu::Swathe::AutoGen::Metadata::DefaultClassApiHolder::DefaultPropertyMetadataApiHolder;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::PropertyMetadataPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::PropertyMetadataPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::Metadata::AssemblyMetadata;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::Metadata::MetadataDispenser;
        using mpl::_1;
        using mpl::_2;
        using mpl::fold;
        using mpl::insert;
        using mpl::map;
        using mpl::pair;

        struct DefaultPropertyMetadataPimplApiHolderImpl : 
            DefaultPropertyMetadataApiHolder
        {
            typedef map<
                pair<PropertyMetadataPersistedHandlerLabel, PropertyMetadataPersistedHandler>,
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<MetadataDispenserLabel, MetadataDispenser>
            > additional_api_cartridges;

            typedef fold<
                additional_api_cartridges,
                DefaultPropertyMetadataApiHolder::api_cartridges,
                insert<_1, _2>
            >::type api_cartridges;
        };

    }   // namespace DefaultPropertyMetadataPimplApiHolderDetail {

    struct DefaultPropertyMetadataPimplApiHolder : 
        DefaultPropertyMetadataPimplApiHolderDetail::DefaultPropertyMetadataPimplApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassPimplApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTPROPERTYMETADATAPIMPLAPIHOLDER_H

