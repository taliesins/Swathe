﻿/* 
 * File: BaseProfilingInfoPimpl.cpp
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

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPIMPL_BASEPROFILINGINFOPIMPL_HPP
#include <Urasandesu/Swathe/Profiling/BaseClassPimpl/BaseProfilingInfoPimpl.hpp>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPIMPLAPIHOLDER_DEFAULTPROFILINGINFOPIMPLAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPimplApiHolder/DefaultProfilingInfoPimplApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSAPIHOLDER_DEFAULTPROCESSPROFILERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassApiHolder/DefaultProcessProfilerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASS_BASEPROCESSPROFILER_H
#include <Urasandesu/Swathe/Profiling/BaseClass/BaseProcessProfiler.h>
#endif

#ifndef URASANDESU_SWATHE_AUTOGEN_PROFILING_DEFAULTCLASSPERSISTEDHANDLERAPIHOLDER_DEFAULTPROCESSPROFILERPERSISTEDHANDLERAPIHOLDER_H
#include <Urasandesu/Swathe/AutoGen/Profiling/DefaultClassPersistedHandlerApiHolder/DefaultProcessProfilerPersistedHandlerApiHolder.h>
#endif

#ifndef URASANDESU_SWATHE_PROFILING_BASECLASSPERSISTEDHANDLER_BASEPROCESSPROFILERPERSISTEDHANDLER_H
#include <Urasandesu/Swathe/Profiling/BaseClassPersistedHandler/BaseProcessProfilerPersistedHandler.h>
#endif

extern template class Urasandesu::Swathe::Profiling::BaseClass::BaseProcessProfiler<>;
extern template class Urasandesu::Swathe::Profiling::BaseClassPersistedHandler::BaseProcessProfilerPersistedHandler<>;
template class Urasandesu::Swathe::Profiling::BaseClassPimpl::BaseProfilingInfoPimpl<>;
SWATHE_DECLARE_BASE_PROFILING_INFO_PIMPL_ADDITIONAL_INSTANTIATION

