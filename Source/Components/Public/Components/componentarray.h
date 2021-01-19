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

class BaseComponentArray {};

template<typename T>
class ComponentArray : public BaseComponentArray {
public:
    ComponentArray() {}

private:
    // Size of component array
    int size = 0;

    std::array<T, MAX_COMPONENTS> componentArray;

    // Maps between entities and indices
    std::unordered_map<Entity, int> entityToIndexMap;
    std::unordered_map<int, Entity> indexToEntityMap;
};

