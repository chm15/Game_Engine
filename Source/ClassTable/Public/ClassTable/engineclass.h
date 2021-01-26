//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to register a Engine Class, which can be sent over
//      networks.
//
//=============================================================================

#pragma once

#include <vector>
#include "classtable.h"

#include <iostream>

class EngineClass {
public:
    const char *networkName;
    ClassTable *table;
    int classID; // TODO: FOR SOME REASON THE CLASSID HERE IS ALWAYS 0.

    static std::vector<EngineClass *> engineClasses;

    static void init() {
        for (EngineClass* ptr : EngineClass::engineClasses) {
            ptr->instantiate();
        }
    }

    void registerEngineClass() {
        //table->registerClass(networkName, classID);
        return;
    }

    // Used to provide instantiation in a non-global scope.
    // Should be called from main at the start of the program.
    virtual void instantiate() {}

public:
    EngineClass(const char* pNetworkName, ClassTable *pTable, int _classID) : 
        networkName(pNetworkName), table(pTable), classID(_classID) {
        //this->engineClasses.push_back(this);
        EngineClass::engineClasses.push_back(this);

    }
};

