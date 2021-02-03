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


        // TODO: Catch error here. Component must be registered with the class
        // table first.
        int classID = T::classID;

        this->componentArrays.insert(
                {classID, std::make_shared<ComponentArray<T>>()}
                );
    }

    void addComponent(int entityID, int componentID) {
        // Use the component's classID (assigned by the classtable.
        // The classID will be used in a map between classID's and
        // component arrays.
        this->componentArrays[componentID]->push_back(entityID);
    }

    void removeComponent(Entity entity, int classID) {
        // use the component's classID to remove the component from the
        // corresponding component array.
    }

    // Returns component of type T associated with entity
    template<typename T>
    T& getComponent(int entityID);

public:
    ComponentManager() = default;

    // Maps from classID to ComponentArray
    std::unordered_map<int, std::shared_ptr<BaseComponentArray> > componentArrays{};


    // Helper function for getting component array.
    //std::shared_ptr<ComponentArray> getComponentArray(int classID) {};

};







template<typename T>
T& ComponentManager::getComponent(int entityID) {
    ComponentArray<T> components =  static_cast<ComponentArray<T>&>(  *(this->componentArrays[T::classID])  );
    return components.getComponent(entityID);
}

