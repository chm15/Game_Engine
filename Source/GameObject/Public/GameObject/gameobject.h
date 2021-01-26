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
#include <Components/componentmanager.h>
#include <ClassTable/iengineclass.h>



class GameObjectInterface;


namespace gameobject {
    extern std::unordered_map<int,GameObjectInterface> g_GameObjectRegistry;
}



/*
 * Used to dynamically load GameObjects into the engine
 * from the global GameObjectRegistry.
 */
class GameObjectInterface {
public:
    GameObjectInterface() = default;
    virtual void load(ComponentManager& cm, int entityID) {}
};



/*
 * Used to create a prebuilt group of components
 */
template<typename T>
class GameObject : public IEngineClass, public GameObjectInterface {
public:
    //virtual ~GameObject() = default;

public:
    GameObject() = default;

    void instantiate() override {
        gameobject::g_GameObjectRegistry.emplace(this->classID, T());
    }
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
