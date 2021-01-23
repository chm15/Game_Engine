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
    int classID;

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
        this->engineClasses.push_back(this);
    }
};

#endif
