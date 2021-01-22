//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to register a Engine Component, which can be sent over
//      networks, and is allocated space in the engine's component manager.
//
//=============================================================================

#pragma once

#include "ClassTable/engineclass.h"
#include "ClassTable/macros.h"
#include "Coordinator/coordinator.h"

namespace coordinator {
    extern Coordinator g_Coordinator;
}


// Templated so component class can be used to allocate space in the component
// manager.
/*
 * :param T Component to be registered.
 * :param pNetworkName std::string The name of the Component.
 * :param *pTable ClassTable The global class table to register with.
 */
template<typename T>
class EngineSystem : public EngineClass {
public:
    EngineSystem(const char* pNetworkName, ClassTable *pTable) : EngineClass(pNetworkName, pTable) {}

    void instantiate() override {
        // EngineClass::init() MUST BE CALLED AT START OF PROGRAM!

        // Get global Coordinator (coordinator::gCoordinator) and add component
        coordinator::g_Coordinator.registerSystem<T>();
    }

};
