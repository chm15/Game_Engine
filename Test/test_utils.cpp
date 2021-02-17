//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Objects library.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"
#include <vector>
#include <Math/vec.h>
#include <Utils/objectloader.h>


//=============== TESTS =======================

void objectloader_test() {
    std::vector<Vec3> vertexBuffer;
    std::vector<unsigned int> indexBuffer;

    loadObjFile("../Assets/cube.obj", vertexBuffer, indexBuffer);

    TEST_ASSERT_EQUAL(indexBuffer[0], 0);  // These values are just hardcoded in from the .obj file.
    TEST_ASSERT_EQUAL(indexBuffer[1], 1);


    return;
}



int main () {

    objectloader_test();


    
    return 0;
}
