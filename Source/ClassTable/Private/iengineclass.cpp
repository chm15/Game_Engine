//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Base class for creating a unique EngineClass.
//
//=============================================================================

#include <vector>
#include "iengineclass.h"

extern int CURRENT_CLASS_ID;


const int IEngineClass::classID = CURRENT_CLASS_ID++;

std::vector<IEngineClass *> IEngineClass::iengineClasses = {};






IEngineClass::IEngineClass() {
    IEngineClass::iengineClasses.push_back(this);
    std::cout << "CONST CALLED! Size: " <<IEngineClass::iengineClasses.size() << std::endl;
    std::cout << "Pointer to engineClasses: " << &iengineClasses << std::endl;
}

void IEngineClass::init() {
    for (IEngineClass* ptr : IEngineClass::iengineClasses) {
        ptr->instantiate();
    }
}
