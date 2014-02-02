﻿/* 
 * File: BasePropertyGeneratorPimpl.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEPROPERTYGENERATORPIMPL_HPP
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BasePropertyGeneratorPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTPROPERTYGENERATORPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPimplApiHolder/DefaultPropertyGeneratorPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPROPERTYGENERATORPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPersistedHandlerApiHolder/DefaultPropertyGeneratorPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPERSISTEDHANDLER_BASEPROPERTYGENERATORPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Metadata/BaseClassPersistedHandler/BasePropertyGeneratorPersistedHandler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeGenerator.h>
#endif

extern template class Urasandesu::Swathe::Metadata::BaseClass::BasePropertyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClassPersistedHandler::BasePropertyGeneratorPersistedHandler<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseTypeGenerator<>;
template class Urasandesu::Swathe::Metadata::BaseClassPimpl::BasePropertyGeneratorPimpl<>;
SWATHE_DECLARE_BASE_PROPERTY_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION

