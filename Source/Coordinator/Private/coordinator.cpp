//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Manages entities, components, and systems. Handles the
//      registration and storage.
//
//=============================================================================

#include <memory>
#include "coordinator.h"
#include "Entities/entitymanager.h"
#include "Components/componentmanager.h"
#include "Systems/systemmanager.h"


// GLOBAL VARIABLES:
namespace coordinator {
    Coordinator g_Coordinator;
}



Coordinator::Coordinator() {
    this->entityManager = std::make_unique<EntityManager>();
    this->componentManager = std::make_unique<ComponentManager>();
    this->systemManager = std::make_unique<SystemManager>();
}
