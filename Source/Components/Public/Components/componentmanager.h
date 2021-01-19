//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once

#include <memory>
#include <unordered_map>
#include <Entities/entity.h>
#include "componentarray.h"

class ComponentManager {
public:

    template<typename T>
    void registerComponent() {
        // Any component that is registered should have already been
        // registered with the Engine's ClassTable. Maybe assert this.
    };

    void addComponent(Entity entity, int classID) {
        // Use the component's classID (assigned by the classtable.
        // The classID will be used in a map between classID's and
        // component arrays.
    }

    void removeComponent(Entity entity, int classID) {
        // use the component's classID to remove the component from the
        // corresponding component array.
    }

public:
    ComponentManager() = default;

    // Maps from classID to ComponentArray
    std::unordered_map<int, std::shared_ptr<ComponentArray> > componentArrays;
    // TODO: COMPONENTARRAY NEEDS A SUPERCLASS THAT ISN'T TEMPLATED!

    // Helper function for getting component array.
    //std::shared_ptr<ComponentArray> getComponentArray(int classID) {};

};



