//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Generic common components.
//
//=============================================================================

#pragma once

#include <vector>
#include <Math/vec.h>
#include <Utils/objectloader.h>
#include <Engine/engineclass.h>

template<typename T>
class Component : public EngineClass<T> {
public:
    void serialize();
};

// POD
struct Mesh : public Component<Mesh> {
    std::vector<Vec3> vertices;
    std::vector<unsigned int> indices;

    Mesh() = default;
    Mesh(const char *objFile) {
        loadObjFile(objFile, this->vertices, this->indices);
    }
};
