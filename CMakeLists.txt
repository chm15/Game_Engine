cmake_minimum_required(VERSION 3.16)

# Project name
project(GameEngine)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(GameEngine Source/main.cpp)


add_subdirectory(Source)


find_package(OpenGL)


target_link_libraries(GameEngine
    Entities
    Components
    Systems
    Engine
    GameObject
    OpenGL
    glfw
    glew
    OpenGL::GL
    )



# Unit Tests
enable_testing()
add_subdirectory(Test)


# Assets
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Source/Assets
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


