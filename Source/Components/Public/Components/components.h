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

    Mesh(std::string _directory, const char *objFile = "mesh.obj", const char *_textureFile = "texture.png") 
        : textureFile(_directory + _textureFile) {
            //===== Make sure directory is terminated with slash =====
            if (_directory.back() != '/') { _directory += '/'; }
        loadObjFile( (_directory + objFile).c_str(), this->vertices, this->indices, this->textureCoords);
    }

    std::string textureFile;

    std::vector<Vec3> vertices;

    std::vector<unsigned int> indices;

    std::vector<float> textureCoords;
};
