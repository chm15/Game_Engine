//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used for assigning a unique classID to each subclass.
//
//=============================================================================

#pragma once


template<typename T>
class EngineClass {
public:
    static const int classID;
public:
    EngineClass() = default;
};


extern int g_CurrentClassID;

template<typename T>
const int EngineClass<T>::classID = g_CurrentClassID++;

