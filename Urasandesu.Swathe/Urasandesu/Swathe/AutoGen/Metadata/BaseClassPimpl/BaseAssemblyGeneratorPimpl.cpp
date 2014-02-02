﻿/* 
 * File: BaseAssemblyGeneratorPimpl.cpp
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

#ifndef URASANDESU_SWATHE_METADATA_BASECLASSPIMPL_BASEASSEMBLYGENERATORPIMPL_HPP
#include <Urasandesu/Swathe/Metadata/BaseClassPimpl/BaseAssemblyGeneratorPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTASSEMBLYGENERATORPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassPimplApiHolder/DefaultAssemblyGeneratorPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTASSEMBLYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultAssemblyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEASSEMBLYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseAssemblyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATAINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATAINFO_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMODULEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultModuleGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMODULEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseModuleGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTTYPEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultTypeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASETYPEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseTypeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTFIELDGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultFieldGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEFIELDGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseFieldGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPROPERTYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultPropertyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPROPERTYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BasePropertyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETHODBODYGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMethodBodyGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETHODBODYGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMethodBodyGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTPARAMETERGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultParameterGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEPARAMETERGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseParameterGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTLOCALGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultLocalGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASELOCALGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseLocalGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTCUSTOMATTRIBUTEGENERATORAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultCustomAttributeGeneratorApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASECUSTOMATTRIBUTEGENERATOR_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseCustomAttributeGenerator.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_METADATA_DEFAULTCLASSAPIHOLDER_DEFAULTMETADATADISPENSERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Metadata/DefaultClassApiHolder/DefaultMetadataDispenserApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_BASECLASS_BASEMETADATADISPENSER_H
#include <Urasandesu/Swathe/Metadata/BaseClass/BaseMetadataDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEINFOAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableInfoApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEINFO_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableInfo.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_HOSTING_DEFAULTCLASSAPIHOLDER_DEFAULTPORTABLEEXECUTABLEWRITERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Hosting/DefaultClassApiHolder/DefaultPortableExecutableWriterApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_HOSTING_BASECLASS_BASEPORTABLEEXECUTABLEWRITER_H
#include <Urasandesu/Swathe/Hosting/BaseClass/BasePortableExecutableWriter.h>
#endif

extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseAssemblyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataInfo<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseModuleGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseTypeGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseFieldGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BasePropertyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMethodBodyGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseParameterGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseLocalGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseCustomAttributeGenerator<>;
extern template class Urasandesu::Swathe::Metadata::BaseClass::BaseMetadataDispenser<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableInfo<>;
extern template class Urasandesu::Swathe::Hosting::BaseClass::BasePortableExecutableWriter<>;
template class Urasandesu::Swathe::Metadata::BaseClassPimpl::BaseAssemblyGeneratorPimpl<>;
SWATHE_DECLARE_BASE_ASSEMBLY_GENERATOR_PIMPL_ADDITIONAL_INSTANTIATION

