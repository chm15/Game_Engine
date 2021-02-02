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
    // The virtual destructor MUST be declared.
    // https://stackoverflow.com/questions/3065154/undefined-reference-to-vtable
    virtual void push_back(int entityID) = 0;
    virtual ~BaseComponentArray() = default;  // Has to be implemented
};

template<typename T>
class ComponentArray : public BaseComponentArray {
public:
    int size() override {
        return arraySize;
    }

    void push_back(int entityID) override {
        this->componentArray[arraySize++] = T();
        return;
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





