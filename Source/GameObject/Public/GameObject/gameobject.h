//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject class.
//
//=============================================================================

#pragma once

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <initializer_list>
#include <Entities/entitymanager.h>
#include <Entities/entity.h>
#include <Engine/engineclass.h>
#include <Components/componentmanager.h>



// Must be initialized with the componentIDs associated with it.
class GameObjectInterface {
public:
    GameObjectInterface(int _classID, std::initializer_list<int> componentIDs) : signature(componentIDs), classID(_classID) {}

    virtual void load(ComponentManager& cm, int entityID) {}

    // Returns true if T is a subset of this objects signature.
    bool hasSignature(std::initializer_list<int> componentIDs);

    virtual ~GameObjectInterface() {}

    const int classID;
protected:
    const std::unordered_set<int> signature;

};


/*
 * Used to create a prebuilt group of components
 */
template<typename T>
class GameObject : public EngineClass<T>, public GameObjectInterface {
public:
    using EngineClass<T>::classID;
    GameObject(std::initializer_list<int> componentIDs) : EngineClass<T>(), GameObjectInterface(this->classID, componentIDs) {}

};


