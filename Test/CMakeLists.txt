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
