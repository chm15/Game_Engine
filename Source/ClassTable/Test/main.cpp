//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Test ClassTable lib.
//
//=============================================================================


#include <iostream>
#include "macros.h"


struct TestClass1 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_CLASS(TestClass1);

struct TestClass2 {
    DECLARE_ENGINE_CLASS();
};
IMPLEMENT_ENGINE_CLASS(TestClass2);

int main () {
    std::cout << "TestClass1 className: " << TestClass1::className << "\nTestClass2 className: " << TestClass2::className << std::endl;
    std::cout << "TestClass1 classID: " << TestClass1::classID<< "\nTestClass2 classID: " << TestClass2::classID << std::endl;
    
    return 0;
}
