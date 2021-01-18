//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Manages entities, components, and systems. Handles the
//      registration and storage.
//
//=============================================================================

#include <string>
#include <iostream>
#include <memory>
#include "Entities/entitymanager.h"
#include "Components/componentmanager.h"
#include "Systems/systemmanager.h"


class Coordinator {
    // Contains a EntityManager, ComponentManager, and SystemManager.
public:
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<ComponentManager> componentManager;
    std::unique_ptr<SystemManager> systemManager;

public:
    Coordinator();

    void registerComponent();
    void registerSystem();
};

