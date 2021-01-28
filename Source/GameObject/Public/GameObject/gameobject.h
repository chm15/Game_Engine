//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject class.
//
//=============================================================================

#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include <Entities/entitymanager.h>
#include <Entities/entity.h>
#include <Engine/engineclass.h>
#include <Components/componentmanager.h>



/*
 * Used to create a prebuilt group of components
 */
template<typename T>
class GameObject : EngineClass<T> {
public:
    GameObject() = default;

    virtual void load(ComponentManager& cm, int entityID) {}
};





/*
// EXAMPLE OF HOW THIS ALL WOULD BE USED:

class Mesh : GameObject {
public:
    void load(ComponentManager cm, int entityID) {
        // Load components into componentManager
        return;
    }
};


Engine.loadGameObject(classID);

Engine::loadGameObject(int classID) {
    gameobject::g_GameObjectRegistry[classID].load(this->componentManager, some_entity_ID);
}


// Then to change the default values, Engine::updateObject(int entityID) would be called.

*/
