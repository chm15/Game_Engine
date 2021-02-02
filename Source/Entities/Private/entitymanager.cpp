//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#include "entitymanager.h"
#include "entity.h"
#include <vector>





std::vector<int> EntityManager::getEntitiesWithGameObjectID(int gameObjectID) {
    std::vector<int> entityIDs;
    for (auto entity : this->entities) {
        if (entity.gameObjectID == gameObjectID) {
            entityIDs.push_back(entity.id);
        }
    }
    return entityIDs;
}




void EntityManager::create(int entityID, int gameObjectID) {
    if (totalEntities < MAX_ENTITIES) {
        this->entities[totalEntities] = Entity(entityID, gameObjectID);
        ++totalEntities;
    } else {
        std::cout << "\n\nMAX ENTITIES REACHED!\n\n" << std::endl;
    }
    return;
}


// Returns newly created entityID
int EntityManager::create(int gameObjectID) {
    // Will create a new Entity with local ID.
    int newEntityID;
    if (totalEntities < MAX_ENTITIES) {
        newEntityID = totalEntities;
        entities[totalEntities] = Entity(newEntityID, gameObjectID);
        ++totalEntities;
    } else {
        std::cout << "\n\nMAX ENTITIES REACHED!\n\n" << std::endl;
        newEntityID = -1;
    }
    return newEntityID;
}
