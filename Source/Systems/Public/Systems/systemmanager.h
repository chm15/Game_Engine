//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <memory>
#include <unordered_map>
#include "system.h"

typedef int ClassID;


class SystemManager {
public:
    template<typename T> 
    void registerSystem() {
        // TODO: Verify that the system is not already registered!
        this->systems.insert({T::classID, std::make_shared<T>()});
        return;
    }

    std::shared_ptr<SystemInterface> getSystem(ClassID ID) {
        return this->systems[ID];
    }

private:
    std::unordered_map<ClassID, std::shared_ptr<SystemInterface>> systems {};
};


#endif
