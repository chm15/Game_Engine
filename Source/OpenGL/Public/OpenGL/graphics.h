//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#pragma once

#include <Systems/system.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class OpenGLGraphicsSystem : public System {
public:
    OpenGLGraphicsSystem();
    void update() override;

private:
    unsigned int vbo;
    unsigned int vao;

    GLFWwindow* window;

    void draw();
    void init();
};
