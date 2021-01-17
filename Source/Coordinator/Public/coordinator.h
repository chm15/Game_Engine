//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Manages entities, components, and systems. Handles the
//      registration and storage.
//
//=============================================================================

#include <string>
#include <iostream>
#include <memory>


class Cooordinator {
    // Contains a EntityManager, ComponentManager, and SystemManager.
public:
    EntityManager* entityManager;
    ComponentManager* componentManager;
    SystemManager* systemManager;

public:
    Coordinator();

    void registerComponent();
    void registerSystem();
};

