//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Components lib.
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





// Declared in Coordinator/Private/coordinator.cpp
namespace coordinator {
    extern Coordinator g_Coordinator;
}




// Set up component for use in ComponentArrayExample
struct ExampleComponent {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_COMPONENT(ExampleComponent);







//=============== TESTS =======================

void componentmanager_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    ComponentManager& exampleComponentManager = *(coordinator::g_Coordinator.componentManager);

    exampleComponentManager.registerComponent<ExampleComponent>();

    int classID = ExampleComponent::classID;

    int arraySize = (exampleComponentManager.componentArrays[classID])->size();

    TEST_ASSERT_EQUAL( arraySize, 0 );
}


void componentarray_test() {
    // This will simply instantiate a componentarray and test the methods.
    ComponentArray<ExampleComponent> exampleComponentArray;

    TEST_ASSERT_EQUAL( exampleComponentArray.size(), 0 );
}


void component_classID_test() {
    ExampleComponent obj;
    int g_classID = obj.getEngineClass()->classID;
    int classID = ExampleComponent::classID;
    TEST_ASSERT_EQUAL( g_classID, classID);
    return;
}





int main () {

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    // ===================================



    componentarray_test();
    componentmanager_test();
    component_classID_test();
    
    return 0;
}
