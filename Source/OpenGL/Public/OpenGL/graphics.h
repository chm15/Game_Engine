//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#pragma once

#include <Systems/system.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Components/components.h>


class OpenGLGraphicsSystem : public System {
public:
    OpenGLGraphicsSystem();
    void update() override;

private:
    unsigned int vao;
    unsigned int vbo;

    GLFWwindow* window;

    void draw(Mesh& mesh);
    void init();
};
