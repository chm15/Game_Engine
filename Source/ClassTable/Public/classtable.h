//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Maintsins a list of all classes that are registered. Useful for
//      networking functions and initializing component arrays automatically.
//
//=============================================================================

#ifndef CLASS_TABLE_H
#define CLASS_TABLE_H

class ClassTable {
public:
    ClassTable() {}


};

class GameEngineClass {
public:
    const char *networkName;
    ClassTable *table;

public:
    GameEngineClass(const char* pNetworkName, ClassTable *pTable) : networkName(pNetworkName), table(pTable) { }

};

#endif
