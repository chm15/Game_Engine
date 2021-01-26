//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Components lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include <unordered_map>
#include "testing/macros.h"
#include <iostream>
#include <vector>

#include <ClassTable/macros.h>
#include <Components/componentmanager.h>
#include <Components/componentarray.h>
#include <Components/macros.h>
#include <Coordinator/coordinator.h>
#include <GameObject/gameobject.h>
#include <ClassTable/engineclass.h>
#include <ClassTable/iengineclass.h>




extern std::vector<EngineClass *> EngineClass::engineClasses;
//extern std::vector<IEngineClass *> IEngineClass::iengineClasses;


namespace gameobject {
    extern std::unordered_map<int,GameObjectInterface> g_GameObjectRegistry;
}



// Declared in Coordinator/Private/coordinator.cpp
namespace coordinator {
    extern Coordinator g_Coordinator;
}




// Set up component for use in ComponentArrayExample
struct ExampleComponent {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_COMPONENT(ExampleComponent);



bool didLoad = false;


// Create GameObject
class Mesh : public GameObject<Mesh> {
public:
    void load(ComponentManager& cm, int entityID) override {
        didLoad = true;
        std::cout << "LOADED" << std::endl;

        return;
    }
};

////////////////////////////////////////
// IF AN INSTANCE OF MESH ISN'T CREATED,
// THE CONSTRUCTOR IS NEVER CALLED,
// MEANING THE CLASSTABLE DOESN'T
// GET AN INSTANCE OF THE CLASS!
////////////////////////////////////////
static Mesh g_Mesh{};

//Engine.loadGameObject(classID);




//=============== TESTS =======================

void gameobject_test() {
    Coordinator& exampleCoordinator = coordinator::g_Coordinator;
    ComponentManager& exampleComponentManager = *(coordinator::g_Coordinator.componentManager);

    std::cout << "About to call load()" << std::endl;
    gameobject::g_GameObjectRegistry[Mesh::classID].load(exampleComponentManager, 69);

}




int main () {
    Mesh mesh{};

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    EngineClass::init();
    IEngineClass::init();
    // ===================================

    std::cout << "Pointer to engineClasses: " << &IEngineClass::iengineClasses << std::endl;

    gameobject_test();

    
    return 0;
}
