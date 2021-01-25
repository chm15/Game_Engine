//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test Math lib.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <Math/vec.h>


//=============== TESTS =======================

void vector_test() {
    Vec<float,3> vecTest;

    Vec3 vecTest2;

    Vec3 vecTest3(1,2,3);

    TEST_ASSERT_EQUAL(vecTest3.x, 1);
    TEST_ASSERT_EQUAL(vecTest3.y, 2);
    TEST_ASSERT_EQUAL(vecTest3.z, 3);

    return;
}



int main () {

    // ===================================
    // MUST BE CALLED AT START OF PROGRAM!
    //EngineClass::init();
    // ===================================

    vector_test();


    
    return 0;
}
