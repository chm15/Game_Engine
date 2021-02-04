//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject manager.
//
//=============================================================================

#include <unordered_map>
#include <vector>
#include <Components/componentmanager.h>
#include "gameobjectmanager.h"



void GameObjectManager::loadGameObject(ComponentManager &cm, int gameObjectID, int entityID) {
    this->gameObjects[gameObjectID]->load(cm, entityID);
    return;
}


std::vector<int> GameObjectManager::getObjectsWithSignature(std::initializer_list<int> componentIDs) {
    std::vector<int> classIDs;

    for (auto &pair : this->gameObjects) {
        auto &go = *(pair.second);
        if (go.hasSignature(componentIDs)) {
            classIDs.push_back(go.classID);
        }
    }
    return classIDs;
}

