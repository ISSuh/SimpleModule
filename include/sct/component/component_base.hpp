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

#ifndef SCT_COMPONENT_COMPONENT_BASE
#define SCT_COMPONENT_COMPONENT_BASE

#include <iostream>
#include <memory>
#include <atomic>

namespace sct {

namespace component {

class ComponentBase : public std::enable_shared_from_this<ComponentBase>{
public:
    virtual ~ComponentBase() {};

    virtual bool Initialize() { return false; }

    virtual bool Process() { return false; }

    virtual bool Shutdown() { return false; }

private:
    std::atomic<bool> m_isShutdown = {false};
    std::string m_componentName;
};

} // namspace component

} // namspace sct

#endif