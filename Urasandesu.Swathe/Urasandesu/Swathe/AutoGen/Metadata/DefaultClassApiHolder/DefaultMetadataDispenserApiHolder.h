﻿/* 
 * File: DefaultMetadataDispenserApiHolder.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_ASSEMBLYMETADATAPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/AssemblyMetadataPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_ASSEMBLYGENERATORPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/AssemblyGeneratorPersistedHandlerLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_FUSION_CLASSLABEL_FUSIONINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Fusion/ClassLabel/FusionInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_FUSIONINFOFWD_H
#include <Urasandesu/Swathe/Fusion/FusionInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_CLASSLABEL_PORTABLEEXECUTABLEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/Hosting/ClassLabel/PortableExecutableInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_PORTABLEEXECUTABLEINFOFWD_H
#include <Urasandesu/Swathe/Hosting/PortableExecutableInfoFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_STRONGNAMING_CLASSLABEL_STRONGNAMEINFOLABEL_H
#include <Urasandesu/Swathe/AutoGen/StrongNaming/ClassLabel/StrongNameInfoLabel.h>
#endif

#ifndef URASANDESU_SWATHE_STRONGNAMING_STRONGNAMEINFOFWD_H
#include <Urasandesu/Swathe/StrongNaming/StrongNameInfoFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassApiHolder { 

    namespace DefaultMetadataDispenserApiHolderDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::Metadata::AssemblyMetadata;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using Urasandesu::Swathe::Metadata::AssemblyMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::AssemblyMetadataPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::AssemblyMetadataPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::Metadata::AssemblyGenerator;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using Urasandesu::Swathe::Metadata::AssemblyGeneratorPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::AssemblyGeneratorPersistedHandlerLabel;
        using Urasandesu::Swathe::Metadata::AssemblyGeneratorPersistedHandler;
        using Urasandesu::Swathe::AutoGen::Fusion::ClassLabel::FusionInfoLabel;
        using Urasandesu::Swathe::Fusion::FusionInfo;
        using Urasandesu::Swathe::AutoGen::Hosting::ClassLabel::PortableExecutableInfoLabel;
        using Urasandesu::Swathe::Hosting::PortableExecutableInfo;
        using Urasandesu::Swathe::AutoGen::StrongNaming::ClassLabel::StrongNameInfoLabel;
        using Urasandesu::Swathe::StrongNaming::StrongNameInfo;
        using mpl::map;
        using mpl::pair;

        struct DefaultMetadataDispenserApiHolderImpl
        {
            typedef map<
                pair<AssemblyMetadataLabel, AssemblyMetadata>,
                pair<AssemblyMetadataPimplLabel, AssemblyMetadataPimpl>,
                pair<AssemblyMetadataPersistedHandlerLabel, AssemblyMetadataPersistedHandler>,
                pair<AssemblyGeneratorLabel, AssemblyGenerator>,
                pair<AssemblyGeneratorPimplLabel, AssemblyGeneratorPimpl>,
                pair<AssemblyGeneratorPersistedHandlerLabel, AssemblyGeneratorPersistedHandler>,
                pair<FusionInfoLabel, FusionInfo>,
                pair<PortableExecutableInfoLabel, PortableExecutableInfo>,
                pair<StrongNameInfoLabel, StrongNameInfo>
            > api_cartridges;
        };
    
    }   // namespace DefaultMetadataDispenserApiHolderDetail {

    struct DefaultMetadataDispenserApiHolder : 
        DefaultMetadataDispenserApiHolderDetail::DefaultMetadataDispenserApiHolderImpl
    {
    };

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace DefaultClassApiHolder { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H

