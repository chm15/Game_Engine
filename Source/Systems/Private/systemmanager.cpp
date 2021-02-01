//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#include <vector>
#include <memory>
#include "system.h"
#include "systemmanager.h"


std::vector<std::shared_ptr<SystemInterface>> SystemManager::getSystems() {
    std::vector<std::shared_ptr<SystemInterface>> systemsVec;
    systemsVec.reserve(this->systems.size());

    for (auto &keyValue : this->systems) {
        systemsVec.push_back(keyValue.second);
    }

    return systemsVec;
}
