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
#include <Objects/objectloader.h>




//=============== TESTS =======================

void objectloader_test() {
    std::vector<Vec3> vertexBuffer;
    std::vector<int> indexBuffer;

    loadObjFile("AssetsTesting/cube.obj", vertexBuffer, indexBuffer);


    return;
}



int main () {

    objectloader_test();


    
    return 0;
}
