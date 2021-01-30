//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject manager.
//
//=============================================================================

#include <unordered_map>
#include <vector>
#include "gameobjectmanager.h"



std::vector<int> GameObjectManager::getObjectsWithSignature(std::initializer_list<int> componentIDs) {
    std::vector<int> classIDs;

    for (auto &pair : this->gameObjects) {
        auto &go = pair.second;
        if (go.hasSignature(componentIDs)) {
            classIDs.push_back(go.classID);
        }
    }
    return classIDs;
}

