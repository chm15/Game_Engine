//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject manager.
//
//=============================================================================

#pragma once

#include <unordered_map>
#include <memory>
#include <Components/componentmanager.h>
#include "gameobject.h"


class GameObjectManager {
public:
    GameObjectManager() = default;

    void loadGameObject(ComponentManager &cm, int gameObjectID, int entityID); 

    template<typename T>
    void registerGameObject() {
        // TODO: Take initializer list to pass init args.
        this->gameObjects.emplace(T::classID, std::make_shared<T>() );
        return;
    }

    // Returns a vector of classIDs that contain the given signature.
    std::vector<int> getObjectsWithSignature(std::initializer_list<int> componentIDs);

private:
    std::unordered_map<int, std::shared_ptr<GameObjectInterface> > gameObjects;
};

