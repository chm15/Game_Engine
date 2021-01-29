//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: 
//
//=============================================================================

#pragma once

#include <Engine/engineclass.h>

class SystemInterface {
public:
    virtual void update() {}
    virtual ~SystemInterface() = default;
};

template<typename T>
class System : public EngineClass<T>, public SystemInterface {
public:

};

