//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Entity. Used to make relationship between components.
//
//=============================================================================

#pragma once


class Entity {
public:
    Entity(int _id) : id(_id) {};
    Entity() = default;

private:
    int id;
};

