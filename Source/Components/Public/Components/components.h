//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Generic common components.
//
//=============================================================================

#pragma once

#include <vector>
#include <Math/vec.h>
#include <Utils/objectloader.h>

class Component {
public:
    void serialize();
};

struct Mesh : Component {
    std::vector<Vec3> vertices;
    std::vector<unsigned int> indices;

    Mesh(const char *objFile) {
        loadObjFile(objFile, this->vertices, this->indices);
    }
};
