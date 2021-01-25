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
#include <Entities/entityregistry.h>


/*
 * The Engine class is used to do high level stuff.
 */
class Engine {
public:
    void loadGameObject(int classID, int entityID) {
        /*
         * Loads GameObject using the GameObjects classID. The GameObject
         * will be loaded with the provided entityID.
         */
        return;
    }

public:
    Engine() = default;
};


