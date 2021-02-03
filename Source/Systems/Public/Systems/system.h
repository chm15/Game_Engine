//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once

#include <Engine/engine.h>
#include <Engine/engineclass.h>


class Engine;

class SystemInterface {
public:
    virtual void update() {}
    virtual ~SystemInterface() = default;
};

template<typename T>
class System : public EngineClass<T>, public SystemInterface {
public:
    System(Engine &_engine) : engine(_engine) {}

    Engine &engine; 
};


