//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Contains macros to register classes for use with the game
//      engine.
//
//=============================================================================

#ifndef MACROS_H
#define MACROS_H

#include <string>


int CURRENT_CLASS_ID = 0;

// If you do a DECLARE_COMPONENT, you need to do this inside the class definition.
#define DECLARE_COMPONENT() \
    static const std::string className;\
    static const int classID\

// DO NOT create this in the header! Put it in the main CPP file.
#define IMPLEMENT_COMPONENT(ComponentName) \
    const std::string ComponentName::className = #ComponentName;\
    const int ComponentName::classID = CURRENT_CLASS_ID++\



#endif
