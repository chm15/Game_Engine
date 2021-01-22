//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Components lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <ClassTable/macros.h>
#include <Systems/componentmanager.h>
#include <Systems/macros.h>
#include <Coordinator/coordinator.h>





// Declared in Coordinator/Private/coordinator.cpp
namespace coordinator {
    extern Coordinator g_Coordinator;
}




// Set up system (Normally declare in the h file)
class SystemExample : System {
    DECLARE_ENGINE_CLASS();
};

// Normally declare in the cpp file
IMPLEMENT_ENGINE_SYSTEM(SystemExample);







//=============== TESTS =======================

void systemmanager_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    SystemManager& exampleSystemManager = *(coordinator::g_Coordinator.systemManager);

    exampleSystemManager.registerSystem<SystemExample>();

    int classID = SystemExample::classID;

}






int main () {

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    // ===================================



    componentmanager_test();
    componentarray_test();
    
    return 0;
}
