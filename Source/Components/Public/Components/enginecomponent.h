//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to register a Engine Component, which can be sent over
//      networks, and is allocated space in the engine's component manager.
//
//=============================================================================

#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include "ClassTable/engineclass.h"
#include "ClassTable/macros.h"
#include "Coordinator/coordinator.h"

namespace coordinator {
    extern Coordinator g_Coordinator;
}


// Templated so component class can be used to allocate space in the component
// manager.
template<typename T>
class EngineComponent : EngineClass {
public:
    EngineComponent(const char* pNetworkName, ClassTable *pTable) {
        EngineClass(pNetworkName, pTable);

        // Get global Coordinator (coordinator::gCoordinator) and add component
        coordinator::g_Coordinator.registerComponent<T>();
    }
};

#endif
