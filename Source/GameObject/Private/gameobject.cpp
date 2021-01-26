//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: GameObject class.
//
//=============================================================================

#include <unordered_map>
#include "gameobject.h"



namespace gameobject {
    std::unordered_map<int,GameObjectInterface> g_GameObjectRegistry{};
}
