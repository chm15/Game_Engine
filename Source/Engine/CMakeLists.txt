set(
    SOURCES 
        "Private/engine.cpp"
        "Private/engineclass.cpp"
)


cmake_minimum_required(VERSION 3.16)

project(Engine)


add_library(${PROJECT_NAME} STATIC ${SOURCES} )

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/Public
    PRIVATE ${PROJECT_SOURCE_DIR}/Public/${PROJECT_NAME}
)

target_link_libraries(Engine Components Systems Entities Math)
