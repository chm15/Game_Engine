//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Components lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <ClassTable/macros.h>
#include <Systems/systemmanager.h>
#include <Systems/enginesystem.h>
#include <Systems/macros.h>
#include <Coordinator/coordinator.h>





// Declared in Coordinator/Private/coordinator.cpp
namespace coordinator {
    extern Coordinator g_Coordinator;
}


// Global variable ONLY FOR TESTING!
bool didUpdate = false;


// Set up system (Normally declare in the h file)
class SystemExample : public System {
public:
    DECLARE_ENGINE_CLASS();
public:
    void update() override {
        didUpdate = true;
        return;
    }
};

// Normally declare in the cpp file
IMPLEMENT_ENGINE_SYSTEM(SystemExample);







//=============== TESTS =======================

void systemmanager_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    SystemManager& exampleSystemManager = *(coordinator::g_Coordinator.systemManager);

    exampleSystemManager.registerSystem<SystemExample>();

    int classID = SystemExample::classID;
    std::shared_ptr<System> sysObject = (exampleSystemManager.getSystem(classID));

    sysObject->update();

    TEST_ASSERT_THROW(didUpdate);
}






int main () {

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    // ===================================


    systemmanager_test();

    
    return 0;
}
