set(
    SOURCES 
        "src/glew.c"
)


cmake_minimum_required(VERSION 3.16)

project(glew)


add_library(${PROJECT_NAME} STATIC ${SOURCES} )

target_include_directories( ${PROJECT_NAME}
    PUBLIC "include"
    PRIVATE "include"
)
