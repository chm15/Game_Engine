//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Engine class.
//
//=============================================================================

#pragma once

#include <string>
#include <iostream>
#include <Entities/entitymanager.h>
#include <Entities/entity.h>
#include <Components/componentmanager.h>
#include <Systems/systemmanager.h>
#include <GameObject/gameobjectmanager.h>
#include <GameObject/gameobject.h>


/*
 * The Engine class is used to do high level stuff.
 */
class Engine {
public:
    template<typename T>
    void registerSystem() {
        this->systemM.registerSystem<T>();
        return;
    }

    template<typename T>
    void registerComponent() {
        this->componentM.registerComponent<T>();
        return;
    }

    template<typename T>
    void registerGameObject() {
        this->gameObjectM.registerGameObject<T>();
        return;
    }

    void loadGameObject(int classID, int entityID);
        /*
         * Loads GameObject using the GameObjects classID. The GameObject
         * will be loaded with the provided entityID.
         */

public:
    Engine() = default;

private:
    EntityManager entityM;
    ComponentManager componentM;
    SystemManager systemM;
    GameObjectManager gameObjectM;
};


