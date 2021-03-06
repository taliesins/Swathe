﻿/* 
 * File: BaseMethodMetadataPersistedHandler.cpp
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


#include "stdafx.h"

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEMETHODMETADATAPERSISTEDHANDLER_HPP
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseMethodMetadataPersistedHandler.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTMETHODMETADATAPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultMethodMetadataPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodMetadata.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYMETADATAAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyMetadataApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYMETADATA_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyMetadata.h>
#endif

extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodMetadata<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyMetadata<>;
template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseMethodMetadataPersistedHandler<>;
SWATHE_DECLARE_BASE_METHOD_METADATA_PERSISTED_HANDLER_ADDITIONAL_INSTANTIATION

