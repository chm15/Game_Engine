//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Math lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <iostream>
#include <Math/vec.h>



struct TestVertex {
    float x, y, z;
};


//=============== TESTS =======================


void vec3size_test() {
    Vec3 vec[10];
    TestVertex vert[10];
    std::cout << "Vertex size: " << sizeof(vert) << " Vec3 size: " << sizeof(vec) << std::endl;
    TEST_ASSERT_EQUAL(sizeof(Vec3), sizeof(TestVertex));
    return;
}


void vector_test() {
    Vec3 vecTest3(1,2,3);

    TEST_ASSERT_EQUAL(vecTest3.x, 1);
    TEST_ASSERT_EQUAL(vecTest3.y, 2);
    TEST_ASSERT_EQUAL(vecTest3.z, 3);

    return;
}



int main () {


    vector_test();
    vec3size_test();


    
    return 0;
}
