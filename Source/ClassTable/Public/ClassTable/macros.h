//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Contains macros to register classes for use with the game
//      engine.
//
//=============================================================================

#ifndef MACROS_H
#define MACROS_H

#include <string>
#include "classtable.h"


int CURRENT_CLASS_ID = 0;

// If you do a DECLARE_COMPONENT, you need to do this inside the class definition.
#define DECLARE_ENGINE_CLASS() \
    virtual EngineClass* getEngineClass(); \
    static ClassTable *classTable; \
    static const std::string className; \
    static const int classID; \
    virtual int YouForgotToImplementOrDeclareServerClass()

// DO NOT create this in the header! Put it in the main CPP file.
#define IMPLEMENT_ENGINE_CLASS(ClassName) \
    \
    namespace classtable { \
        extern ClassTable g_ClassTable; \
    }\
    \
    static EngineClass g_##ClassName##_ClassReg( \
            #ClassName,  \
            &classtable::g_ClassTable \
    ); \
    \
	EngineClass* ClassName::getEngineClass() {return &g_##ClassName##_ClassReg;} \
	ClassTable *ClassName::classTable = &classtable::g_ClassTable;\
	int ClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
    \
    /* Patchy solution. will probably be removed. */ \
    const std::string ClassName::className = #ClassName; \
    const int ClassName::classID = CURRENT_CLASS_ID++


// The classtable::g_ClassTable refers to the global ClassTable in the classtable namespace




#define DECLARE_ENGINE_ENTITY()
#define DECLARE_ENGINE_COMPONENT()
#define DECLARE_ENGINE_SYSTEM()


#endif
