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
#include <stb_image/stb_image.h>
#include "graphics.h"



//===== CALLBACK FUNCTIONS =====
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}



//===== CLASS DEFINITIONS ===== 

OpenGLGraphicsSystem::OpenGLGraphicsSystem(Engine &_engine) : System(_engine) {
    this->init();  // OpenGL related inits
    return;
}


//std::vector<int> getEntitiesWithSignature(std::initializer_list<int> signature);
//T& Engine::getComponent(int entityID) {


void OpenGLGraphicsSystem::update() {
    bool shouldClose = glfwWindowShouldClose(this->window);
    if (shouldClose) {
        std::cout << "Implement close method in OpenGL lib!" << std::endl;
    }
    glfwPollEvents();



    std::vector<int> entitiesWithSignature = this->engine.getEntitiesWithSignature({Mesh::classID});


    //===== Binding =====
    glBindVertexArray(this->vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);

    //===== Clear buffers =====
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //===== Main =====
    for (int entityID : entitiesWithSignature) {
        Mesh &mesh = this->engine.getComponent<Mesh>(entityID);

        this->draw(mesh);
    }

    glfwSwapBuffers(this->window);

    //===== Cleanup =====
    glBindVertexArray(0);
    return;
}

void OpenGLGraphicsSystem::draw(Mesh& mesh) {
    // Draw mesh. Assumes vao, vbo, ebo is already bound.

    //===== Load vbo, ebo =====
    //vbo
    glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * 3 * sizeof(float),  // Vec3
            &mesh.vertices[0], GL_STREAM_DRAW);


    //===== Load texture =====
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(mesh.textureFile.c_str(), &width, &height, &nrChannels, 0);
    if (data) {
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.textureCoords.size() * sizeof(float),
                &mesh.textureCoords[0], GL_STREAM_DRAW);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
        glEnableVertexAttribArray(1);

    }
    else {
        // Texture failed to load.
        std::cout << "Texture failed to load from path: " << mesh.textureFile << std::endl; 
    }
    stbi_image_free(data);


    //ebo (attribpointer not required because ebo just restructures the vao)
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(int),
            &mesh.indices[0], GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);  // must be void* for compatibility with old OpenGL
    glEnableVertexAttribArray(0);


    //===== Load shader program =====
    glUseProgram(this->shaderProgram);


    //===== Specify uniforms =====
    //glUniform3f(offsetUniform, 0.0f, 0.0f, 0.0f);


    // Bind VAO right before drawing.  TODO: This seems redundant.
    glBindVertexArray(this->vao);


    //===== Draw =====
    glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, (void*)0);


    //===== Cleanup =====
    glUseProgram(0);


    int error = glGetError();  
    if (error) {
        std::cout << "OpenGL Error: " << error << std::endl;
    }
    return;
}

void OpenGLGraphicsSystem::init() {
    // Initialize OpenGL stuff

    glfwSetErrorCallback(this->errorCallback);  // One of the few functions that can be called before init.

    assert(glfwInit());  // GLFW failed to init

    //glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

    this->window = glfwCreateWindow( 1280, 960, "Game Engine", NULL, NULL);
    assert(this->window != NULL);  // Window failed to init

    glfwMakeContextCurrent(this->window); // Initialize GLEW
    glewExperimental = GL_TRUE;
    assert(glewInit()==0);  // GLEW failed to init

    int width, height;
    glfwGetFramebufferSize(this->window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(this->window, framebuffer_size_callback);


    // vao, vbo, ebo
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ebo);
    glGenTextures(1, &this->texture);

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
    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragmentShader);


    //===== Set to wireframe for debug =====
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    return;
}

void OpenGLGraphicsSystem::errorCallback(int error, const char* description) {
    std::cout << "Error: " << description << std::endl;
}


