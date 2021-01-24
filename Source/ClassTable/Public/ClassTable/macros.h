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


// ClassReg is the registry to be used.
#define IMPLEMENT_ENGINE_CLASS_WITH_TYPE_TEMPLATED(ClassName, ClassReg) \
    \
    const std::string ClassName::classname = #ClassName; \
    const int ClassName::classID = CURRENT_CLASS_ID++; \
    \
    namespace classtable { \
        extern ClassTable g_ClassTable; \
    }\
    \
    static ClassReg<ClassName> g_##ClassName##_ClassReg( \
            #ClassName, \
            &classtable::g_ClassTable, \
            ClassName::classID \
            ); \
    \
    EngineClass* ClassName::getEngineClass() {return &g_##ClassName##_ClassReg;} \
    int ClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
    ClassTable *ClassName::classTable = &classtable::g_ClassTable
    

// ClassReg is the registry to be used.
// Use to register class with EngineClass or subclass of EngineClass. 
//
// Extra arguments can be provided.
#define IMPLEMENT_ENGINE_CLASS_WITH_TYPE_AND_ARGS(ClassName, ClassReg, ...) \
    \
    const int ClassName::classID = CURRENT_CLASS_ID++; \
    const std::string ClassName::className = #ClassName; \
    \
    namespace classtable { \
        extern ClassTable g_ClassTable; \
    }\
    \
    extern int CURRENT_CLASS_ID; \
    \
    static ClassReg g_##ClassName##_ClassReg( \
            #ClassName,  \
            &classtable::g_ClassTable, \
            ClassName::classID, \
            __VA_ARGS__ \
    ); \
    \
	EngineClass* ClassName::getEngineClass() {return &g_##ClassName##_ClassReg;} \
	int ClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
	ClassTable *ClassName::classTable = &classtable::g_ClassTable


// ClassReg is the registry to be used.
// Use to register class with EngineClass or subclass of EngineClass
#define IMPLEMENT_ENGINE_CLASS_WITH_TYPE(ClassName, ClassReg) \
    \
    const std::string ClassName::className = #ClassName; \
    const int ClassName::classID = CURRENT_CLASS_ID++; \
    \
    namespace classtable { \
        extern ClassTable g_ClassTable; \
    }\
    \
    extern int CURRENT_CLASS_ID; \
    \
    static ClassReg g_##ClassName##_ClassReg( \
            #ClassName,  \
            &classtable::g_ClassTable, \
            ClassName::classID \
    ); \
    \
	EngineClass* ClassName::getEngineClass() {return &g_##ClassName##_ClassReg;} \
	int ClassName::YouForgotToImplementOrDeclareServerClass() {return 0;} \
	ClassTable *ClassName::classTable = &classtable::g_ClassTable



// If you do a DECLARE_COMPONENT, you need to do this inside the class definition.
#define DECLARE_ENGINE_CLASS() \
    virtual EngineClass* getEngineClass(); \
    static ClassTable *classTable; \
    static const std::string className; \
    static const int classID; \
    virtual int YouForgotToImplementOrDeclareServerClass()


#define IMPLEMENT_ENGINE_CLASS(ClassName) \
    IMPLEMENT_ENGINE_CLASS_WITH_TYPE(ClassName, EngineClass)


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





