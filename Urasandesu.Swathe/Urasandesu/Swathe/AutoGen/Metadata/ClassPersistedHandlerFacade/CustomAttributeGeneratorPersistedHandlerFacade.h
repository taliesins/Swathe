﻿/* 
 * File: CustomAttributeGeneratorPersistedHandlerFacade.h
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
#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERFACADE_CUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFACADE_H
#define URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERFACADE_CUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFACADE_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSAPIAT_CUSTOMATTRIBUTEGENERATORAPIAT_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassApiAt/CustomAttributeGeneratorApiAt.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSFACADE_CUSTOMATTRIBUTEGENERATORFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassFacade/CustomAttributeGeneratorFacade.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSLABEL_METADATADISPENSERLABEL_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassLabel/MetadataDispenserLabel.h>
#endif

namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPersistedHandlerFacade { 

    namespace CustomAttributeGeneratorPersistedHandlerFacadeDetail {

        using namespace Urasandesu::CppAnonym;
        using namespace Urasandesu::CppAnonym::Traits;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassApiAt::CustomAttributeGeneratorApiAt;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassFacade::CustomAttributeGeneratorFacade;
        using Urasandesu::Swathe::AutoGen::Metadata::ClassLabel::MetadataDispenserLabel;

        template<
            class ApiHolder
        >    
        struct CustomAttributeGeneratorPersistedHandlerFacadeImpl : 
            CustomAttributeGeneratorFacade<ApiHolder>
        {
            typedef typename CustomAttributeGeneratorApiAt<ApiHolder, MetadataDispenserLabel>::type metadata_dispenser_label_type;
        };
    
    }   // namespace CustomAttributeGeneratorPersistedHandlerFacadeDetail {

    template<
        class ApiHolder
    >    
    struct CustomAttributeGeneratorPersistedHandlerFacade : 
        CustomAttributeGeneratorPersistedHandlerFacadeDetail::CustomAttributeGeneratorPersistedHandlerFacadeImpl<ApiHolder>
    {
    };

#define SWATHE_BEGIN_CUSTOM_ATTRIBUTE_GENERATOR_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS \
    typedef Urasandesu::Swathe::AutoGen::Metadata::ClassPersistedHandlerFacade::CustomAttributeGeneratorPersistedHandlerFacade<ApiHolder> facade;

#define SWATHE_DECLARE_CUSTOM_ATTRIBUTE_GENERATOR_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS \
    SWATHE_DECLARE_CUSTOM_ATTRIBUTE_GENERATOR_FACADE_TYPEDEF_ALIAS \
    typedef typename facade::metadata_dispenser_label_type metadata_dispenser_label_type; \
    friend typename metadata_dispenser_label_type; \

#define SWATHE_END_CUSTOM_ATTRIBUTE_GENERATOR_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

}}}}}   // namespace Urasandesu { namespace Swathe { namespace AutoGen { namespace Metadata { namespace ClassPersistedHandlerFacade { 

#endif  // URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERFACADE_CUSTOMATTRIBUTEGENERATORPERSISTEDHANDLERFACADE_H

