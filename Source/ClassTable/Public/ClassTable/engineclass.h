//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to register a Engine Class, which can be sent over
//      networks.
//
//=============================================================================

#ifndef ENGINE_CLASS_H
#define ENGINE_CLASS_H

#include "classtable.h"

class EngineClass {
public:
    const char *networkName;
    ClassTable *table;

public:
    EngineClass(const char* pNetworkName, ClassTable *pTable) : networkName(pNetworkName), table(pTable) { }
};

#endif
