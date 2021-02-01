//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Entity. Used to make relationship between components.
//
//=============================================================================

#pragma once


class Entity {
public:
    Entity() : id(-1), gameObjectID(-1) {}

    Entity(int _id, int _gameObjectID) : id(_id), gameObjectID(_gameObjectID) {}

    Entity(const Entity &obj) : id(obj.id), gameObjectID(obj.gameObjectID) {}

    int const gameObjectID;

private:
    int id;
};

