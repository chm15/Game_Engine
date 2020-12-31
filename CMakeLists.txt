cmake_minimum_required(VERSION 3.10)

# Project name
project(Server)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
#add_executable(Server server.cpp)


add_subdirectory(Source)

