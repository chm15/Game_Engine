cmake_minimum_required(VERSION 3.16)

# Project name
project(GameEngine)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(GameEngine Source/main.cpp)


add_subdirectory(Source)

