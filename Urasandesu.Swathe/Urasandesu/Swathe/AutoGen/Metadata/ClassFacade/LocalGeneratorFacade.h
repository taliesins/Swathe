﻿/* 
 * File: LocalGeneratorFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALGENERATORFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALGENERATORFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_LOCALGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/LocalGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_LOCALGENERATORPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/LocalGeneratorPersistedHandlerFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorFwd.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METHODBODYGENERATORPIMPLFWD_H
#include <Urasandesu/Swathe/Metadata/MethodBodyGeneratorPimplFwd.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_ASSEMBLYGENERATORLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/AssemblyGeneratorLabel.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPIMPLLABEL_ASSEMBLYGENERATORPIMPLLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPimplLabel/AssemblyGeneratorPimplLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

    namespace LocalGeneratorFacadeDetail {
        
        namespace mpl = boost::mpl;
        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::LocalGeneratorApiAt;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPimpl;
        using Urasandesu::Swathe::Metadata::LocalGenerator;
        using Urasandesu::Swathe::Metadata::LocalGeneratorPersistedHandler;
        using Urasandesu::Swathe::Metadata::MethodBodyGenerator;
        using Urasandesu::Swathe::Metadata::MethodBodyGeneratorPimpl;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::AssemblyGeneratorLabel;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassPimplLabel::AssemblyGeneratorPimplLabel;
        using mpl::vector;
        
        template<
            class ApiHolder
        >    
        struct LocalGeneratorFacadeImpl
        {
            typedef LocalGenerator class_type;
            typedef LocalGeneratorPimpl class_pimpl_type;
            typedef LocalGeneratorPimpl local_generator_pimpl_label_type;
            typedef typename LocalGeneratorApiAt<ApiHolder, AssemblyGeneratorLabel>::type assembly_generator_label_type;
            typedef typename LocalGeneratorApiAt<ApiHolder, AssemblyGeneratorPimplLabel>::type assembly_generator_pimpl_label_type;

            typedef LocalGeneratorPimpl local_generator_pimpl_label_type;
            typedef LocalGenerator local_generator_label_type;
            typedef LocalGeneratorPersistedHandler local_generator_persisted_handler_label_type;
            typedef MethodBodyGenerator method_body_generator_label_type;
            typedef MethodBodyGeneratorPimpl method_body_generator_pimpl_label_type;

            
            typedef Nil base_heap_provider_type;
            
            #define SWATHE_DECLARE_LOCAL_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
                typedef typename facade::base_heap_provider_type base_heap_provider_type; \
                friend typename base_heap_provider_type; \
            
        };
    
    }   // namespace LocalGeneratorFacadeDetail {

    template<
        class ApiHolder
    >    
    struct LocalGeneratorFacade : 
        LocalGeneratorFacadeDetail::LocalGeneratorFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_LOCAL_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::LocalGeneratorFacade<ApiHolder> facade;

#define SWATHE_DECLARE_LOCAL_GENERATOR_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_LOCAL_GENERATOR_EMPTY_HEAP_PROVIDER_TYPEDEF_ALIAS \
    typedef typename facade::class_type class_type; \
    typedef typename facade::class_pimpl_type class_pimpl_type; \
    friend typename class_pimpl_type; \
    typedef typename facade::local_generator_pimpl_label_type local_generator_pimpl_label_type; \
    friend typename local_generator_pimpl_label_type; \
    typedef typename facade::assembly_generator_label_type assembly_generator_label_type; \
    typedef typename facade::assembly_generator_pimpl_label_type assembly_generator_pimpl_label_type; \
    friend typename assembly_generator_label_type; \
    friend typename assembly_generator_pimpl_label_type; \
    typedef typename facade::local_generator_pimpl_label_type local_generator_pimpl_label_type; \
    typedef typename facade::local_generator_label_type local_generator_label_type; \
    typedef typename facade::local_generator_persisted_handler_label_type local_generator_persisted_handler_label_type; \
    typedef typename facade::method_body_generator_label_type method_body_generator_label_type; \
    typedef typename facade::method_body_generator_pimpl_label_type method_body_generator_pimpl_label_type; \
    friend typename local_generator_pimpl_label_type; \
    friend typename local_generator_label_type; \
    friend typename local_generator_persisted_handler_label_type; \
    friend typename method_body_generator_label_type; \
    friend typename method_body_generator_pimpl_label_type; \

#define SWATHE_END_LOCAL_GENERATOR_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_LOCALGENERATORFACADE_H

