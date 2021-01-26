cmake_minimum_required(VERSION 3.16)

project(Testing)


# ClassTable
add_executable( test_classtable test_classtable.cpp )
add_test( classtable test_classtable )

target_link_libraries(test_classtable ClassTable Components)



# Components
add_executable( test_components test_components.cpp )
add_test( components test_components )

target_link_libraries(test_components ClassTable Components Coordinator)

# Systems
add_executable( test_systems test_systems.cpp )
add_test( systems test_systems )

target_link_libraries(test_systems ClassTable Systems Coordinator)

# Entities
add_executable( test_entities test_entities.cpp )
add_test( entities test_entities )

target_link_libraries(test_entities ClassTable Systems Coordinator Entities)

# Math
add_executable( test_math test_math.cpp )
add_test( math test_math )

target_link_libraries(test_math Math)

# GameObject
add_executable( test_gameobject test_gameobject.cpp )
add_test( gameobject test_gameobject)

target_link_libraries(test_gameobject GameObject ClassTable)
