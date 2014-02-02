﻿/* 
 * File: BaseAssemblyGeneratorPersistedHandler.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEASSEMBLYGENERATORPERSISTEDHANDLER_HPP
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BaseAssemblyGeneratorPersistedHandler.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTASSEMBLYGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultAssemblyGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataDispenser.h>
#endif

extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataDispenser<>;
template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BaseAssemblyGeneratorPersistedHandler<>;
SWATHE_DECLARE_BASE_ASSEMBLY_GENERATOR_PERSISTED_HANDLER_ADDITIONAL_INSTANTIATION

