//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to register a Engine Class, which can be sent over
//      networks.
//
//=============================================================================

#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include <vector>
#include "classtable.h"

class EngineClass {
public:
    const char *networkName;
    ClassTable *table;

    static std::vector<EngineClass *> engineClasses;

    static void init() {
        for (EngineClass* ptr : EngineClass::engineClasses) {
            ptr->instantiate();
        }
    }

    // Used to provide instantiation in a non-global scope.
    // Should be called from main at the start of the program.
    virtual void instantiate() {}

public:
    EngineClass(const char* pNetworkName, ClassTable *pTable) : networkName(pNetworkName), table(pTable) {
        this->engineClasses.push_back(this);
    }
};

#endif
