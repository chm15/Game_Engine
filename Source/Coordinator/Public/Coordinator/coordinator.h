//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Manages entities, components, and systems. Handles the
//      registration and storage.
//
//=============================================================================

#pragma once

#include <string>
#include <iostream>
#include <memory>
#include "Entities/entitymanager.h"
#include "Components/componentmanager.h"
#include "Systems/systemmanager.h"
#include "Entities/entityregistry.h"


class Coordinator {
    // Contains a EntityManager, ComponentManager, and SystemManager.
public:
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<ComponentManager> componentManager;
    std::unique_ptr<SystemManager> systemManager;
    std::unique_ptr<EntityRegistry> entityRegistry;

public:
    Coordinator();

    template<typename T>
    void registerComponent() {
        this->componentManager->registerComponent<T>();
    }

    template<typename T>
    void registerSystem() {
        this->systemManager->registerSystem<T>();
    }
};

