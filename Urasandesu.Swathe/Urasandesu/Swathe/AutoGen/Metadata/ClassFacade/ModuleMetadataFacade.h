﻿/* 
 * File: ModuleMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_MODULEMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/ModuleMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_MODULEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/ModuleMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_METADATADISPENSERPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/MetadataDispenserPimplLabel.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_TYPEMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/TypeMetadataPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace ModuleMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::ModuleMetadataApiAt;
        using Urasandesu::Swathe::Metadata::ModuleMetadataPimpl;
        using Urasandesu::Swathe::Metadata::ModuleMetadata;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::MetadataDispenserPimplLabel;
        using Urasandesu::Swathe::Metadata::TypeMetadata;
        using Urasandesu::Swathe::Metadata::TypeMetadataPimpl;
        using Urasandesu::Swathe::Metadata::TypeMetadataPersistedHandler;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct ModuleMetadataFacadeImpl
        {
            typedef ModuleMetadata class_type;
            typedef ModuleMetadataPimpl class_pimpl_type;
            typedef ModuleMetadataPimpl module_metadata_pimpl_label_type;
            typedef typename ModuleMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename ModuleMetadataApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;
            typedef typename ModuleMetadataApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
            typedef typename ModuleMetadataApiAt<ApiHolder, MetadataDispenserPimplLabel>::type metadata_dispenser_pimpl_label_type;

            typedef ModuleMetadataPimpl module_metadata_pimpl_label_type;
            typedef ModuleMetadata module_metadata_label_type;
            typedef TypeMetadata type_metadata_label_type;
            typedef TypeMetadataPimpl type_metadata_pimpl_label_type;
            typedef TypeMetadataPersistedHandler type_metadata_persisted_handler_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_MODULE_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace ModuleMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct ModuleMetadataFacade : 
        ModuleMetadataFacadeDetail::ModuleMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_MODULE_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::ModuleMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_MODULE_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_MODULE_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::module_metadata_pimpl_label_type module_metadata_pimpl_label_type; \
    friend typename module_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    typedef typename facade::metadata_dispenser_pimpl_label_type metadata_dispenser_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    friend typename metadata_dispenser_label_type; \
    friend typename metadata_dispenser_pimpl_label_type; \
    typedef typename facade::module_metadata_pimpl_label_type module_metadata_pimpl_label_type; \
    typedef typename facade::module_metadata_label_type module_metadata_label_type; \
    typedef typename facade::type_metadata_label_type type_metadata_label_type; \
    typedef typename facade::type_metadata_pimpl_label_type type_metadata_pimpl_label_type; \
    typedef typename facade::type_metadata_persisted_handler_label_type type_metadata_persisted_handler_label_type; \
    friend typename module_metadata_pimpl_label_type; \
    friend typename module_metadata_label_type; \
    friend typename type_metadata_label_type; \
    friend typename type_metadata_pimpl_label_type; \
    friend typename type_metadata_persisted_handler_label_type; \

#define SWATHE_END_MODULE_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_MODULEMETADATAFACADE_H

