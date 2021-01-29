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

private:
    std::unordered_map<int,GameObjectInterface> gameObjects;
};

