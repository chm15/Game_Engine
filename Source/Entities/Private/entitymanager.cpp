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
