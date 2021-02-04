//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Stores components. Usually used by the global coordinator.
//
//=============================================================================

#pragma once

#include <array>
#include <unordered_map>
#include <Entities/entity.h>

#define MAX_COMPONENTS 64

#define EntityID int

class BaseComponentArray {
public:
    virtual int size() = 0;
    
    virtual void push_back(int entityID) = 0;

    // The virtual destructor MUST be declared.
    // https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable
    virtual ~BaseComponentArray() = default;  // Has to be implemented
};

template<typename T>
class ComponentArray : public BaseComponentArray {
public:
    int size() override {
        return arraySize;
    }

    void push_back(int entityID) override {
        int componentPos = arraySize++;
        this->componentArray[componentPos] = T();
        this->entityToIndexMap[entityID] = componentPos;
        return;
    }
    
    // Does not have interface. Must be static_casted to use this.
    // Copy the given component into array.
    template<typename TT>
    void push_back(TT& component) {
        int componentPos = arraySize++;
        this->componentArray[componentPos] = component;
        this->entityToIndexMap[component.entityID] = componentPos;
        return;
    }


    T& getComponent(int entityID) {
        int index = entityToIndexMap[entityID];
        return componentArray[index];
    }

private:
    // Size of component array
    int arraySize = 0;

    std::array<T, MAX_COMPONENTS> componentArray;

    // Maps between entities and indices
    // Use the entitie's ID for the first key (int)
    std::unordered_map<EntityID, int> entityToIndexMap;
    std::unordered_map<int, EntityID> indexToEntityMap;
};





