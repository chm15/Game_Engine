//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject class.
//
//=============================================================================

#include "gameobject.h"



bool GameObjectInterface::hasSignature(std::initializer_list<int> componentIDs) {
    bool containsSignature = true;
    std::vector<int> classIDs {componentIDs};
    for (int classID : classIDs) {
        if (!(this->signature.count(classID))) {
            containsSignature = false;
            break;
        }
    }
    return containsSignature;
}

