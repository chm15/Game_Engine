//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Contains macros to register classes for use with the game
//      engine.
//
//=============================================================================

#pragma once

#include <string>
#include "classtable.h"
#include "engineclass.h"


int CURRENT_CLASS_ID = 0;



#define IMPLEMENT_ENGINE_CLASS_WITH_TYPE_TEMPLATED(ClassName, ClassReg) \
    \
    namespace classtable { \
        extern ClassTable g_ClassTable; \
    }\
    \
    static ClassReg<ClassName> g_##ClassName##_ClassReg( \
            #ClassName, \
            &classtable::g_ClassTable \
            ); \
    \
    EngineClass* ClassName::getEngineClass() {return &g_##ClassName##_ClassReg;} \
    ClassTable *ClassName::classTable = &classtable::g_ClassTable;\
    int ClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
    \
    const std::string ClassName::classname = #ClassName; \
    const int ClassName::classID = CURRENT_CLASS_ID++
    


// Use to register class with EngineClass or subclass of EngineClass
#define IMPLEMENT_ENGINE_CLASS_WITH_TYPE(ClassName, ClassReg) \
    \
    namespace classtable { \
        extern ClassTable g_ClassTable; \
    }\
    \
    static ClassReg g_##ClassName##_ClassReg( \
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



// If you do a DECLARE_COMPONENT, you need to do this inside the class definition.
#define DECLARE_ENGINE_CLASS() \
    virtual EngineClass* getEngineClass(); \
    static ClassTable *classTable; \
    static const std::string className; \
    static const int classID; \
    virtual int YouForgotToImplementOrDeclareServerClass()


//
//// DO NOT create this in the header! Put it in the main CPP file.
//#define IMPLEMENT_ENGINE_CLASS(ClassName) \
//    \
//    namespace classtable { \
//        extern ClassTable g_ClassTable; \
//    }\
//    \
//    static EngineClass g_##ClassName##_ClassReg( \
//            #ClassName,  \
//            &classtable::g_ClassTable \
//    ); \
//    \
//	EngineClass* ClassName::getEngineClass() {return &g_##ClassName##_ClassReg;} \
//	ClassTable *ClassName::classTable = &classtable::g_ClassTable;\
//	int ClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
//    \
//    /* Patchy solution. will probably be removed. */ \
//    const std::string ClassName::className = #ClassName; \
//    const int ClassName::classID = CURRENT_CLASS_ID++
//

// The classtable::g_ClassTable refers to the global ClassTable in the classtable namespace

#define IMPLEMENT_ENGINE_CLASS(ClassName) \
    IMPLEMENT_ENGINE_CLASS_WITH_TYPE(ClassName, EngineClass)


#define DECLARE_ENGINE_ENTITY()
#define DECLARE_ENGINE_COMPONENT()
#define DECLARE_ENGINE_SYSTEM()


