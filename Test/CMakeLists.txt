cmake_minimum_required(VERSION 3.16)

project(Testing)


# Math
add_executable( test_math test_math.cpp )
add_test( math test_math )

target_link_libraries(test_math Math)


# EngineClass
add_executable( test_engineclass test_engineclass.cpp )
add_test( engineclass test_engineclass )

target_link_libraries(test_engineclass Engine)
