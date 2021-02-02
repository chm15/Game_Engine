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

    int create(int gameObjectID);

    std::vector<int> getEntitiesWithGameObjectID(int gameObjectID);

private:
    int totalEntities = 0;
    Entity entities[MAX_ENTITIES];
};



