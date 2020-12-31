//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Contains macros to register classes for use with the game
//      engine.
//
//=============================================================================

#ifndef MACROS_H
#define MACROS_H

#include <string>
#include "common.h"


int CURRENT_CLASS_ID = 0;

// If you do a DECLARE_COMPONENT, you need to do this inside the class definition.
#define DECLARE_COMPONENT() \
    virtual GameEngineClass* getServerClass(); \
    static ClassTable *classTable; \
    static const std::string className; \
    static const int classID; \
    virtual int YouForgotToImplementOrDeclareServerClass()

// DO NOT create this in the header! Put it in the main CPP file.
#define IMPLEMENT_COMPONENT(ComponentName) \
    extern classtable::g_ClassTable; \
    \
    static GameEngineClass g_##ComponentName##_ClassReg( \
            #ComponentName,  \
            &classtable::g_ClassTable, \
    ); \
    \
	GameEngineClass* ComponentName::getServerClass() {return &g_##ComponentName##_ClassReg;} \
	ClassTable *ComponentName::classTable = &classtable::g_ClassTable;\
	int DLLClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
    \
    /* Patchy solution. will probably be removed. */ \
    const std::string ComponentName::className = #ComponentName; \
    const int ComponentName::classID = CURRENT_CLASS_ID++


#endif
