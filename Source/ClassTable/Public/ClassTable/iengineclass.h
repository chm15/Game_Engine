//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Base class for creating a unique EngineClass.
//
//=============================================================================

#pragma once

#include <vector>
#include <iostream>



class IEngineClass {
public:
    static const char *networkName;
    static const int classID;


    static void init();

    // Used to provide instantiation in a non-global scope.
    // Should be called from main at the start of the program.
    virtual void instantiate() {}

public:
    IEngineClass();

//private:
    static std::vector<IEngineClass *> iengineClasses;
};

