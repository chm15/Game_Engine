//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Entities lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <iostream>
#include <vector>

#include <ClassTable/macros.h>
#include <ClassTable/engineclass.h>

#include <Components/componentmanager.h>
#include <Components/componentarray.h>
#include <Components/macros.h>
#include <Coordinator/coordinator.h>
#include <Entities/entityregistry.h>
#include <Entities/engineentity.h>
#include <Entities/macros.h>





// Declared in Coordinator/Private/coordinator.cpp
namespace coordinator {
    extern Coordinator g_Coordinator;
}


//////////////////////////////////////////////////////////////
// I can't stress HOW IMPORTANT THIS LINE IS!
// Without this line, the static member variable
// EngineClass::engineClasses will be reinitialized to zero.
extern std::vector<EngineClass *> EngineClass::engineClasses;
//////////////////////////////////////////////////////////////


// Set up components 
struct Component1 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_COMPONENT(Component1);

struct Component2 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_COMPONENT(Component2);


struct Entity1 {
    DECLARE_ENGINE_CLASS();
};
//IMPLEMENT_ENGINE_CLASS(Entity1);
IMPLEMENT_ENGINE_ENTITY(Entity1, 
        Component1::classID,
        Component2::classID
        );



//=============== TESTS =======================

void entityregistry_generic_test() {
    EntityRegistry entreg;

    std::vector<int> fakeComponentIDs = {1,3,4};

    entreg.registerEntity(69, fakeComponentIDs);

    std::vector<int> getComps = entreg.getEntity(69);
    TEST_ASSERT_EQUAL(fakeComponentIDs[1], getComps[1]);
    return;
}

void entityregistry_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    EntityRegistry& entityRegistry = *(coordinator::g_Coordinator.entityRegistry);

    int classID = Entity1::classID;

    std::vector<int> compCID = entityRegistry.getEntity(classID);

    std::cout << compCID.size() << std::endl;

    TEST_ASSERT_EQUAL(compCID[0], Component1::classID);
    TEST_ASSERT_EQUAL(compCID[1], Component2::classID);
    return;
}






int main () {
    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    std::cout << "TOTAL ENGINECLASSES: " << EngineClass::engineClasses.size() << std::endl;
    // ===================================

    entityregistry_generic_test();

    entityregistry_test();

    
    return 0;
}
