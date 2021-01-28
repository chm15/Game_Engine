//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#include <vector>
#include <cassert>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Components/components.h>
#include "graphics.h"


OpenGLGraphicsSystem::OpenGLGraphicsSystem() : System() {
    this->init();
    return;
}

void OpenGLGraphicsSystem::update() {
    //===== Binding =====
    glBindVertexArray(this->vao);

    //===== Main =====
    std::vector<Mesh> meshes;  // TODO: INITIALIZE this with meshes

    for (Mesh& mesh : meshes) {
        this->draw(mesh);
    }

    glfwSwapBuffers(window);

    //===== Cleanup =====
    glBindVertexArray(0);
    return;
}

void OpenGLGraphicsSystem::draw(Mesh& mesh) {
    // Draw mesh. Assumes vao is already bound.
    //===== Clear buffers =====
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //===== Load shader program =====
    //glUseProgram(theProgram);

    //===== Specify uniforms =====
    //glUniform3f(offsetUniform, 0.0f, 0.0f, 0.0f);

    //===== Draw =====
    //glDrawElements(GL_TRIANGLES, ARRAY_COUNT(indexData), GL_UNSIGNED_SHORT, 0);

    //===== Cleanup =====
    glUseProgram(0);

    return;
}

void OpenGLGraphicsSystem::init() {
    // Initialize OpenGL stuff
    assert(glfwInit());  // GLFW failed to init

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

    this->window = glfwCreateWindow( 1280, 960, "Game Engine", NULL, NULL);
    assert(this->window != NULL);  // Window failed to init

    glfwMakeContextCurrent(this->window); // Initialize GLEW
    assert(glewInit()==0);  // GLEW failed to init


    // Initialize class members
    glGenVertexArrays(1, &this->vao);

    return;
}

