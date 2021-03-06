//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Engine class.
//
//=============================================================================

#include <memory>
#include <vector>
#include "engine.h"


void Engine::loadGameObject(int gameObjectID) {
    int entityID = this->entityM.create(gameObjectID);
    this->gameObjectM.loadGameObject(this->componentM, gameObjectID, entityID);
    return;
}


void Engine::loadGameObject(int gameObjectID, int entityID) {
    /*
     * Loads GameObject using the GameObjects classID. The GameObject
     * will be loaded with the provided entityID.
     */
    this->entityM.create(entityID, gameObjectID);
    this->gameObjectM.loadGameObject(this->componentM, gameObjectID, entityID);
    return;
}

void Engine::run() {
    while (true) {
        this->runSystems();
    }
}

void Engine::runSystems() {
    auto systems = this->systemM.getSystems();
    for (auto &system : systems) {
        system->update();
    }
    return;
}

// The signature is a initializer list of componentIDs (classIDs)
std::vector<int> Engine::getEntitiesWithSignature(std::initializer_list<int> signature) {
    std::vector<int> entityIDs;

    // First get the classIDs of all GameObjects that have the signature
    std::vector<int> gameObjectIDs = gameObjectM.getObjectsWithSignature(signature);


    // Now get all entityIDs that are of the returned GameObject types
    for (int goID : gameObjectIDs) {
        std::vector<int> tempIDs = entityM.getEntitiesWithGameObjectID(goID);
        for (int id : tempIDs) {
            entityIDs.push_back(id);
        }
    }
    // User can now use the entityIDs to retrieve components
    return entityIDs;
}


