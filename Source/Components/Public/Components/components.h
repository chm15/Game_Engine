//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Generic common components.
//
//=============================================================================

#pragma once

#include <array>
#include <Math/vec.h>

class Component {
public:
    void serialize();
};

struct Mesh : Component {
    std::vector<Vec3> vertices;
};
