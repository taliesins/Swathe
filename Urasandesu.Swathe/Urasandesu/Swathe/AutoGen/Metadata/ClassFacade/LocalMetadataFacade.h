﻿/* 
 * File: LocalMetadataFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALMETADATAFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALMETADATAFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_LOCALMETADATAAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/LocalMetadataApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALMETADATAPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalMetadataPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYMETADATAPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyMetadataPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYMETADATALABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyMetadataLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYMETADATAPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyMetadataPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace LocalMetadataFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::LocalMetadataApiAt;
        using Urasandesu::Swathe::Metadata::LocalMetadataPimpl;
        using Urasandesu::Swathe::Metadata::LocalMetadata;
        using Urasandesu::Swathe::Metadata::LocalMetadataPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadata;
        using Urasandesu::Swathe::Metadata::MethodBodyMetadataPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyMetadataLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyMetadataPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct LocalMetadataFacadeImpl
        {
            typedef LocalMetadata class_type;
            typedef LocalMetadataPimpl class_pimpl_type;
            typedef LocalMetadataPimpl local_metadata_pimpl_label_type;
            typedef typename LocalMetadataApiAt<ApiHolder, AssemblyMetadataLabel>::type assembly_metadata_label_type;
            typedef typename LocalMetadataApiAt<ApiHolder, AssemblyMetadataPimplLabel>::type assembly_metadata_pimpl_label_type;

            typedef LocalMetadataPimpl local_metadata_pimpl_label_type;
            typedef LocalMetadata local_metadata_label_type;
            typedef LocalMetadataPersistedHandler local_metadata_persisted_handler_label_type;
            typedef MethodBodyMetadata method_body_metadata_label_type;
            typedef MethodBodyMetadataPimpl method_body_metadata_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_LOCAL_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace LocalMetadataFacadeDetail {

    template<
        class ApiHolder
    >    
    struct LocalMetadataFacade : 
        LocalMetadataFacadeDetail::LocalMetadataFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_LOCAL_METADATA_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::LocalMetadataFacade<ApiHolder> facade;

#define SWATHE_DECLARE_LOCAL_METADATA_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_LOCAL_METADATA_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::local_metadata_pimpl_label_type local_metadata_pimpl_label_type; \
    friend typename local_metadata_pimpl_label_type; \
    typedef typename facade::assembly_metadata_label_type assembly_metadata_label_type; \
    typedef typename facade::assembly_metadata_pimpl_label_type assembly_metadata_pimpl_label_type; \
    friend typename assembly_metadata_label_type; \
    friend typename assembly_metadata_pimpl_label_type; \
    typedef typename facade::local_metadata_pimpl_label_type local_metadata_pimpl_label_type; \
    typedef typename facade::local_metadata_label_type local_metadata_label_type; \
    typedef typename facade::local_metadata_persisted_handler_label_type local_metadata_persisted_handler_label_type; \
    typedef typename facade::method_body_metadata_label_type method_body_metadata_label_type; \
    typedef typename facade::method_body_metadata_pimpl_label_type method_body_metadata_pimpl_label_type; \
    friend typename local_metadata_pimpl_label_type; \
    friend typename local_metadata_label_type; \
    friend typename local_metadata_persisted_handler_label_type; \
    friend typename method_body_metadata_label_type; \
    friend typename method_body_metadata_pimpl_label_type; \

#define SWATHE_END_LOCAL_METADATA_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALMETADATAFACADE_H

