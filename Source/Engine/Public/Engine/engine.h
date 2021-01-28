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
#include <GameObject/gameobject.h>


/*
 * The Engine class is used to do high level stuff.
 */
class Engine {
public:
    template<typename T>
    void registerSystem() {
        return;
    }

    template<typename T>
    void registerComponent() {
        return;
    }

    template<typename T>
    void registerGameObject() {
        return;
    }

    void loadGameObject(int classID, int entityID);
        /*
         * Loads GameObject using the GameObjects classID. The GameObject
         * will be loaded with the provided entityID.
         */

public:
    Engine() = default;
};


