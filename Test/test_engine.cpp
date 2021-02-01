//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Engine
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"
#include <vector>
#include <Engine/engine.h>
#include <Components/components.h>
#include <OpenGL/graphics.h>



class Cube : public GameObject<Cube> {
public:
    Cube() : GameObject<Cube>{Mesh::classID} {}
    // Contains Mesh component
    void load(ComponentManager& cm, int entityID) override {}
};



//=============== TESTS =======================

void engine_test() {
    Engine engine;

    //===== Register Components =====
    engine.registerComponent<Mesh>();   // Defined in <Components/components.h>
    //engine.registerComponent<Transform>();
    
    //===== Register Systems =====
    //engine.registerSystem<OpenGLGraphicsSystem>();  // Defined in <OpenGL/graphics.h>

    //===== Register GameObjects =====
    engine.registerGameObject<Cube>();  // TODO: Provide variadic where GameObject init args can be passed through

    engine.loadGameObject(Cube::classID, 69);  // 69 is the entityID. This simulates a server authoritative ID system.

    std::vector<int> entityIDs = engine.getEntitiesWithSignature({Mesh::classID});

    TEST_ASSERT_EQUAL( entityIDs.size(), 1);
    TEST_ASSERT_EQUAL( entityIDs[0], 69);
    return;
}



int main () {

    engine_test();
    

    return 0;
}
