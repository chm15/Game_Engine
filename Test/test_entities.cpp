//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Entities lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <ClassTable/macros.h>
#include <Components/componentmanager.h>
#include <Components/componentarray.h>
#include <Components/macros.h>
#include <Coordinator/coordinator.h>
#include <Entities/entityregistry.h>
#include <Entities/macros.h>





// Declared in Coordinator/Private/coordinator.cpp
namespace coordinator {
    extern Coordinator g_Coordinator;
}




// Set up components 
struct Componentt1 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_COMPONENT(Component1);

struct Component2 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_COMPONENT(Component2);


struct Entity1 {
    DECLARE_ENGINE_CLASS();
}
IMPLEMENT_ENGINE_CLASS(Entity1);
REGISTER_ENTITY(Entity1::classID, 
        Component1,
        Component2
        );



//=============== TESTS =======================

void entityregistry_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    ComponentManager& exampleComponentManager = *(coordinator::g_Coordinator.componentManager);

    exampleComponentManager.registerComponent<ExampleComponent>();

    int classID = ExampleComponent::classID;

    int arraySize = (exampleComponentManager.componentArrays[classID])->size();

    TEST_ASSERT_EQUAL( arraySize, 0 );
}






int main () {

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    // ===================================



    
    return 0;
}
