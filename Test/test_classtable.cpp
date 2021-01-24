//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test ClassTable lib.
//
//=============================================================================

#include "testing/macros.h"


#include <iostream>
#include <ClassTable/macros.h>


//////////////////////////////////////////////////////////////
// I can't stress HOW IMPORTANT THIS LINE IS!
// Without this line, the static member variable
// EngineClass::engineClasses will be reinitialized to zero.
extern std::vector<EngineClass *> EngineClass::engineClasses;
//////////////////////////////////////////////////////////////



struct TestClass1 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_CLASS(TestClass1);

struct TestClass2 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_CLASS(TestClass2);


void classtable_test() {
    int TC1_ID = TestClass1::classID;
    int TC2_ID = TestClass2::classID;

    TEST_ASSERT_EQUAL( TC1_ID, 0 );
    TEST_ASSERT_EQUAL( TC2_ID, 1 );

    TEST_ASSERT_THROW( TestClass1::className == "TestClass1" );
    TEST_ASSERT_THROW( TestClass2::className == "TestClass2" );

    TEST_ASSERT_EQUAL(EngineClass::engineClasses.size(), 2);
}

int main () {
    EngineClass::init();
    std::cout << "TOTAL ENGINECLASSES: " << EngineClass::engineClasses.size() << std::endl;
    //std::cout << "TestClass1 className: " << TestClass1::className << "\nTestClass2 className: " << TestClass2::className << std::endl;
    //std::cout << "TestClass1 classID: " << TestClass1::classID<< "\nTestClass2 classID: " << TestClass2::classID << std::endl;
    classtable_test();
    
    return 0;
}
