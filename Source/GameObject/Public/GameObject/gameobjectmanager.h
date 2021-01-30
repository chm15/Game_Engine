//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject manager.
//
//=============================================================================

#pragma once

#include <unordered_map>
#include "gameobject.h"


class GameObjectManager {
public:
    GameObjectManager() = default;

    template<typename T>
    void registerGameObject() {
        // TODO: Take initializer list to pass init args.
        this->gameObjects.emplace(T::classID,T{});
        return;
    }

    // Returns a vector of classIDs that contain the given signature.
    std::vector<int> getObjectsWithSignature(std::initializer_list<int> componentIDs);

    //std::vector<int> getGameObjectsWithSignature()

private:
    std::unordered_map<int,GameObjectInterface> gameObjects;
};

