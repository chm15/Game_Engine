//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Entities lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <iostream>

#include <ClassTable/macros.h>
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

void entityregistry_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    EntityRegistry& entityRegistry = *(coordinator::g_Coordinator.entityRegistry);

    int classID = Entity1::classID;

    std::vector<int> compCID = entityRegistry.getEntity(classID);

    std::cout << compCID.size() << std::endl;

    //TEST_ASSERT_EQUAL(compCID[0], Component1::classID);
    //TEST_ASSERT_EQUAL(compCID[1], Component2::classID);
    return;
}






int main () {

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    std::cout << "TOTAL ENGINECLASSES: " << EngineClass::engineClasses.size() << std::endl;
    // ===================================


    entityregistry_test();

    
    return 0;
}
