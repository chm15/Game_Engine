//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Generic common components.
//
//=============================================================================

#pragma once

#include <vector>
#include <string>
#include <Math/vec.h>
#include <Utils/objectloader.h>
#include <Engine/engineclass.h>

template<typename T>
class Component : public EngineClass<T> {
public:
    Component() : entityID(-1) {}
    void serialize();

    int entityID;  // used to link the component with a certain entity.
};

// POD
struct Mesh : public Component<Mesh> {
    Mesh() = default;

    Mesh(const char *objFile, std::string _textureName = "texture.png") 
        : textureName(_textureName) {
        loadObjFile(objFile, this->vertices, this->indices);
    }

    std::string textureName;

    std::vector<Vec3> vertices;

    std::vector<unsigned int> indices;
};
