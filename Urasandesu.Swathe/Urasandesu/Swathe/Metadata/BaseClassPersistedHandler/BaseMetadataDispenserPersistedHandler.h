﻿/* 
 * File: BaseMetadataDispenserPersistedHandler.h
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
#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETADATADISPENSERPERSISTEDHANDLER_H
#define URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETADATADISPENSERPERSISTEDHANDLER_H

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_CLASSPERSISTEDHANDLERFACADE_METADATADISPENSERPERSISTEDHANDLERFACADE_H
#include <Urasandesu/Swathe/AutoGen/Metadata/ClassPersistedHandlerFacade/MetadataDispenserPersistedHandlerFacade.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETADATADISPENSERPERSISTEDHANDLERFWD_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMetadataDispenserPersistedHandlerFwd.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPersistedHandler { 

    using Urasandesu::CppAnonym::Utilities::TempPtr;
    
    template<
        class ApiHolder
    >    
    class BaseMetadataDispenserPersistedHandler
    {
    public:
        SWATHE_BEGIN_METADATA_DISPENSER_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
            SWATHE_DECLARE_METADATA_DISPENSER_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS
        SWATHE_END_METADATA_DISPENSER_PERSISTED_HANDLER_FACADE_TYPEDEF_ALIAS

        typedef TempPtr<metadata_dispenser_label_type> sender_type;

        BaseMetadataDispenserPersistedHandler(metadata_info_label_type *pMetaInfo);
        void operator()(sender_type *pSender, void *pArg);
        
    private:
        mutable metadata_info_label_type *m_pMetaInfo;

    };

}}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata { namespace BaseClassPersistedHandler { 

#endif  // URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETADATADISPENSERPERSISTEDHANDLER_H

