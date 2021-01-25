//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject class.
//
//=============================================================================

#pragma once

#include <string>
#include <iostream>
#include <Entities/entitymanager.h>
#include <Entities/entity.h>
#include <Components/componentmanager.h>


/*
 * The Engine class is used to do high level stuff.
 */
template<typename T>
class GameObject {
public:
    virtual void load(ComponentManager cm, int entityID) = 0;
    //virtual ~GameObject() = default;
};


