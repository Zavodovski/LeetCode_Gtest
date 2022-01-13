cmake_minimum_required(VERSION 3.21)
project(LeetCode_Clion)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
include_directories(googletest/include googletest)

add_executable(LeetCode_Clion main.cpp)
target_link_libraries(LeetCode_Clion gtest gtest_main)
