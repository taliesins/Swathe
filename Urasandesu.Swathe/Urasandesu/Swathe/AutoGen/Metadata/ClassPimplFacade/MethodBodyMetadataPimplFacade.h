﻿/* 
 * File: MethodBodyMetadataPimplFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODBODYMETADATAPIMPLFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODBODYMETADATAPIMPLFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_METHODBODYMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/MethodBodyMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_METHODBODYMETADATAFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/MethodBodyMetadataFacade.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERLABEL_METHODBODYMETADATAPERSISTEDHANDLERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerLabel/MethodBodyMetadataPersistedHandlerLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPimplFacade { 

    namespace MethodBodyMetadataPimplFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::MethodBodyMetadataApiAt;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::MethodBodyMetadataFacade;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerLabel::MethodBodyMetadataPersistedHandlerLabel;

        template<
            class ApiHolder
        >    
        struct MethodBodyMetadataPimplFacadeImpl : 
            MethodBodyMetadataFacade<ApiHolder>
        {
            typedef typename MethodBodyMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename MethodBodyMetadataApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
            typedef typename MethodBodyMetadataApiAt<ApiHolder, MethodBodyMetadataPersistedHandlerLabel>::type method_body_metadata_persisted_handler_label_type;
        };
    
    }   // namespace MethodBodyMetadataPimplFacadeDetail {

    template<
        class ApiHolder
    >    
    struct MethodBodyMetadataPimplFacade : 
        MethodBodyMetadataPimplFacadeDetail::MethodBodyMetadataPimplFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_METHOD_BODY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassPimplFacade::MethodBodyMetadataPimplFacade<ApiHolder> facade;

#define SWATHE_DECLARE_METHOD_BODY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_METHOD_BODY_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::method_body_metadata_persisted_handler_label_type method_body_metadata_persisted_handler_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename method_body_metadata_persisted_handler_label_type; \

#define SWATHE_END_METHOD_BODY_METADATA_PIMPL_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPimplFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLFACADE_METHODBODYMETADATAPIMPLFACADE_H

