cmake_minimum_required(VERSION 3.16)

# Project name
project(GameEngine)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(GameEngine Source/main.cpp)


add_subdirectory(Source)

target_link_libraries(GameEngine Components)



# Unit Tests
enable_testing()
add_subdirectory(Test)
