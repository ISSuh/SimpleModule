/******************************************************************************
 * Copyright 2019 The ISSuh Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef SMT_LOADER_MODULELOADERUTIL_HPP_   
#define SMT_LOADER_MODULELOADERUTIL_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <mutex>
#include <memory>

#include "smt/module/ModuleBase.hpp"
#include "smt/loader/ModuleLoader.hpp"
#include "smt/loader/ModuleFactory.hpp"

namespace smt {
namespace loader {

namespace util {

using UserModuleFactoryMap = std::map<std::string, smt::loader::AbstractModuleFactoryBase*>;

// std::recursive_mutex& getModuleFactorMapMutex() {
//   static std::recursive_mutex instance;
//   return instance;
// }

// std::recursive_mutex& getModuleNamebyFactoryMapMutex() {
//   static std::recursive_mutex instance;
//   return instance;
// }

UserModuleFactoryMap& getUserModulFactoryMap() {
    static UserModuleFactoryMap instance;
    return instance;
}

template<typename Module, typename BaseModule>
void registUserModule(const std::string& className, const std::string& baseCalssName) {
    AbstractModlueFactory<BaseModule>* moduleFactrory =
      new ModuleFactory<Module, BaseModule>(className, baseCalssName);

    std::cout << "RegistClass" << std::endl;

    // getModuleFactorMapMutex.lock();
    auto& factoryMap = getUserModulFactoryMap();
    factoryMap[className] = moduleFactrory;
    // getModuleFactorMapMutex.unlock();
}


template <typename BaseModule>
std::shared_ptr<BaseModule> createModule(const std::string& className) {
    auto& factoryMap = getUserModulFactoryMap();

    AbstractModlueFactory<BaseModule>* factory = nullptr;
    if (factoryMap.find(className) != factoryMap.end()) {
        // factory = dynamic_cast<AbstractModlueFactory<Base>* >(factoryMap[className]);
        factory = (AbstractModlueFactory<BaseModule>*)(factoryMap[className]);
    }

    std::shared_ptr<BaseModule> userModule;
    if (factory) {
        userModule = factory->createModule();
    }

    return classObj;
}

}  // namespace util
}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADERUTIL_HPP_
