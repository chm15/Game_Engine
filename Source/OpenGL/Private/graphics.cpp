//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include "graphics.h"


OpenGLGraphicsSystem::OpenGLGraphicsSystem() : System() {
    this->init();
    return;
}

void OpenGLGraphicsSystem::update() {

    return;
}

void OpenGLGraphicsSystem::draw() {
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

    this->window = glfwCreateWindow( 1280, 960, "Game Engine", NULL, NULL);
    assert(this->window != NULL);  // Window failed to init

    glfwMakeContextCurrent(this->window); // Initialize GLEW
    assert(glewInit()==0);  // GLEW failed to init
    return;
}
