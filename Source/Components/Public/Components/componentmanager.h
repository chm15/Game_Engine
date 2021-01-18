//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once

#include <Entities/entity.h>

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

};



