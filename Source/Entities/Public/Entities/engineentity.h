//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to track entities.
//
//=============================================================================

#pragma once

#include "ClassTable/engineclass.h"
#include "ClassTable/macros.h"
#include "Coordinator/coordinator.h"

namespace coordinator {
    extern Coordinator g_Coordinator;
}

/*

template<typename T>
class EngineComponent : public EngineClass {
public:
    EngineComponent(const char* pNetworkName, ClassTable *pTable) : EngineClass(pNetworkName, pTable) {

    }


    void instantiate() override {
        // EngineClass::init() MUST BE CALLED AT START OF PROGRAM!

        // Get global Coordinator (coordinator::gCoordinator) and add component
        coordinator::g_Coordinator.registerComponent<T>();
    }

};

*/
