//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Associate entities with components. Alike a blueprint.
//
//=============================================================================

#pragma once

#include <unordered_map>
#include <vector>


class EntityRegistry {
public:
    void registerEntity(int classID, std::vector<int> componentCID) {
        // Takes the EngineClass given classID to register components.
        // The components MUST have a EngineClass classID as well!
        this->registeredEntities.emplace(classID, componentCID);
        return;
    }

    std::vector<int> getEntity(int classID) {
        // Returns classIDs of components associated with a certain classID.
        // TODO: Make this safer.
        return registeredEntities[classID];
    }

private:
    std::unordered_map<int, std::vector<int> > registeredEntities;
};
