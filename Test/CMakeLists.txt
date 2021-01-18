cmake_minimum_required(VERSION 3.16)

project(Testing)



add_executable( test_classtable test_classtable.cpp )
add_test( classtable test_classtable )



target_link_libraries(test_classtable ClassTable )
