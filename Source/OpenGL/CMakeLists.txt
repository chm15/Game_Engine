set(
    SOURCES 
        "Private/graphics.cpp"
)


cmake_minimum_required(VERSION 3.16)

project(OpenGL)


add_library(${PROJECT_NAME} STATIC ${SOURCES} )

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/Public
    PRIVATE ${PROJECT_SOURCE_DIR}/Public/${PROJECT_NAME}
)

find_package(OpenGL)

target_link_libraries(OpenGL Math Components Systems Engine glew glfw OpenGL::GL )
