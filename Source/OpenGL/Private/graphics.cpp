//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#include <vector>
#include <cassert>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Components/components.h>
#include "graphics.h"


OpenGLGraphicsSystem::OpenGLGraphicsSystem() : System() {
    this->init();  // OpenGL related inits
    return;
}

void OpenGLGraphicsSystem::update() {
    //===== Binding =====
    glBindVertexArray(this->vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);

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
    // Draw mesh. Assumes vao, vbo, ebo is already bound.
    //===== Clear buffers =====
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //===== Load vbo, ebo =====
    //vbo
    glBufferData(GL_ARRAY_BUFFER, sizeof(mesh.vertices),
            static_cast<void *>(mesh.vertices.data()), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  // must be void* for compatibility with old OpenGL
    glEnableVertexAttribArray(0);
    //ebo (attribpointer not required because ebo just restructures the vao)
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(mesh.indices),
            static_cast<void *>(mesh.indices.data()), GL_STATIC_DRAW);


    //===== Load shader program =====
    glUseProgram(this->shaderProgram);

    //===== Specify uniforms =====
    //glUniform3f(offsetUniform, 0.0f, 0.0f, 0.0f);

    //===== Draw =====
    //glDrawElements(GL_TRIANGLES, ARRAY_COUNT(indexData), GL_UNSIGNED_INT, 0);

    //===== Cleanup =====
    glUseProgram(0);

    return;
}

void OpenGLGraphicsSystem::init() {
    // Initialize OpenGL stuff

    glfwSetErrorCallback(this->errorCallback);  // One of the few functions that can be called before init.

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


    // vao, vbo, ebo
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ebo);

    // shaders
    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    this->shaderProgram = glCreateProgram();

    //===== Vertex shader =====
    std::string vertexShaderSource;
    loadShader("Assets/Shaders/vertex.glsl", vertexShaderSource);
    const char *vs = vertexShaderSource.data();
    glShaderSource(this->vertexShader, 1, &vs, NULL);
    glCompileShader(this->vertexShader);
    {  // error handling
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            std::cout << vs << std::endl;
        }
    }

    //===== Fragment shader =====
    std::string fragmentShaderSource;
    loadShader("Assets/Shaders/fragment.glsl", fragmentShaderSource);
    const char *fs = fragmentShaderSource.data();
    glShaderSource(this->fragmentShader, 1, &fs, NULL);
    glCompileShader(fragmentShader);
    {  // error handling
        int success;
        char infoLog[512];
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            std::cout << fs << std::endl;
        }
    }

    //===== Shader program =====
    glAttachShader(this->shaderProgram, this->vertexShader);
    glAttachShader(this->shaderProgram, this->fragmentShader);
    glLinkProgram(this->shaderProgram);
    {  // error handling
        int success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
    }

    return;
}

void OpenGLGraphicsSystem::errorCallback(int error, const char* description) {
    std::cout << "Error: " << description << std::endl;
}
