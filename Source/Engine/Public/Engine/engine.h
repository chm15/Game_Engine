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
    // Register System with the Engine
    template<typename T>
    void registerSystem();

    // Register Component with the Engine
    template<typename T>
    void registerComponent();

    // Register GameObject with the Engine
    template<typename T>
    void registerGameObject();

    // Add GameObject to the scene
    // Will be added with provided entityID
    void loadGameObject(int classID, int entityID);

    // Run main game loop
    void run();

    // Run all systems
    void runSystems();
public:
    Engine() = default;

private:
    EntityManager entityM;
    ComponentManager componentM;
    SystemManager systemM;
    GameObjectManager gameObjectM;
};





template<typename T>
void Engine::registerSystem() {
    this->systemM.registerSystem<T>();
    return;
}

template<typename T>
void Engine::registerComponent() {
    this->componentM.registerComponent<T>();
    return;
}

template<typename T>
void Engine::registerGameObject() {
    this->gameObjectM.registerGameObject<T>();
    return;
}
