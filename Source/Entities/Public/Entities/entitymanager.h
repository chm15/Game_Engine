//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#include <iostream>
#include <vector>
#include "entity.h"

#pragma once

#define MAX_ENTITIES 420


class EntityManager {
public:
    EntityManager() = default;

    void create(int entityID, int gameObjectID);

    // T is the GameObject
    template<typename T>
    void create();

    std::vector<int> getEntitiesWithGameObjectID(int gameObjectID);

private:
    int totalEntities = 0;
    Entity entities[MAX_ENTITIES];
};






template<typename T>
void EntityManager::create() {
    // Will create a new Entity with local ID.
    if (totalEntities < MAX_ENTITIES) {
        entities[totalEntities] = Entity(totalEntities, T::classID);
        ++totalEntities;
    } else {
        std::cout << "\n\nMAX ENTITIES REACHED!\n\n" << std::endl;
    }
    return;
}
