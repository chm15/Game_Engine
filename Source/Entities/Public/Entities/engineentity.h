//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to register a Engine Component, which can be sent over
//
//      This is strictly used by macros.
//
//=============================================================================

#pragma once

#include <initializer_list>
#include <vector>
#include <ClassTable/engineclass.h>
#include <ClassTable/macros.h>
#include <Coordinator/coordinator.h>


namespace coordinator {
    extern Coordinator g_Coordinator;
}

template<typename T>
class EngineEntity : public EngineClass {
public:
    EngineEntity(const char* pNetworkName, ClassTable *pTable, int _classID,
            std::initializer_list<int> _componentClassIDs) 
        : EngineClass(pNetworkName, pTable, _classID), componentClassIDs(_componentClassIDs) { }

    void instantiate() override {
        // EngineClass::init() MUST BE CALLED AT START OF PROGRAM!

        // Get global Coordinator (coordinator::g_Coordinator)
        //Coordinator& coord = coordinator::g_Coordinator;

        coordinator::g_Coordinator.entityRegistry->registerEntity(this->classID, componentClassIDs);

        return;
    }
private:
    std::vector<int> componentClassIDs;
};




/*

// Templated so component class can be used to allocate space in the component
// manager.

template<typename T>
class EngineComponent : public EngineClass {
public:
    EngineComponent(const char* pNetworkName, ClassTable *pTable, int _classID) : EngineClass(pNetworkName, pTable, _classID) {

    }


    void instantiate() override {
        // EngineClass::init() MUST BE CALLED AT START OF PROGRAM!

        // Get global Coordinator (coordinator::gCoordinator) and add component
        coordinator::g_Coordinator.registerComponent<T>();
    }

};
*/
