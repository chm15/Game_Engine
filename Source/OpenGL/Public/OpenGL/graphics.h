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
    unsigned int vao;  // vertex array object
    unsigned int vbo;  // vertex buffer object
    unsigned int ebo;  // element buffer object

    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;

    GLFWwindow* window;

    void draw(Mesh& mesh);
    void init();
    static void errorCallback(int error, const char* description);
};
