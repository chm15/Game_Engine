//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#include <iostream>
#include "entity.h"

#pragma once

#define MAX_ENTITIES 420


class EntityManager {
public:
    EntityManager() = default;
    template<typename T>
    void create() {
        // Will create a new Entity with local ID.
        if (totalEntities < MAX_ENTITIES) {
            entities[totalEntities] = Entity(totalEntities, T::classID);
            ++totalEntities;
        } else {
            std::cout << "\n\nMAX ENTITIES REACHED!\n\n" << std::endl;
        }
        return;
    }

private:
    int totalEntities = 0;
    Entity entities[MAX_ENTITIES];
};


