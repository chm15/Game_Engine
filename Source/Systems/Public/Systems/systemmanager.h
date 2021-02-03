//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <Engine/engine.h>
#include "system.h"

typedef int ClassID;

class SystemInterface;
class Engine;

class SystemManager {
public:
    SystemManager(Engine &_engine) : engine(_engine) {}

    template<typename T> 
    void registerSystem() {
        // TODO: Verify that the system is not already registered!
        this->systems.insert({T::classID, std::make_shared<T>(this->engine)});
        return;
    }

    std::shared_ptr<SystemInterface> getSystem(ClassID ID) {
        return this->systems[ID];
    }

    std::vector<std::shared_ptr<SystemInterface>> getSystems();

private:
    std::unordered_map<ClassID, std::shared_ptr<SystemInterface>> systems {};
    Engine &engine;
};

