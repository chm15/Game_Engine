//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Engine class.
//
//=============================================================================

#include <memory>
#include "engine.h"


void Engine::loadGameObject(int classID, int entityID) {
    /*
     * Loads GameObject using the GameObjects classID. The GameObject
     * will be loaded with the provided entityID.
     */
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
