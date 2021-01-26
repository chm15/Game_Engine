//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test EngineClass.
//
//=============================================================================

//TEST_ASSERT_EQUAL( TC1_ID, 0 );
//TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );

#include "testing/macros.h"

#include <Engine/engineclass.h>




class SC1 : public EngineClass<SC1> { };
class SC2 : public EngineClass<SC2> { };



//=============== TESTS =======================

void engineclass_test() {
    SC1 sc1;
    SC2 sc2;

    TEST_ASSERT_EQUAL(SC1::classID, 1);
    TEST_ASSERT_EQUAL(sc1.classID, SC1::classID);

    TEST_ASSERT_EQUAL(SC2::classID, 2);
    TEST_ASSERT_EQUAL(sc2.classID, SC2::classID);
    
    return;
}



int main () {

    engineclass_test();


    
    return 0;
}
