cmake_minimum_required(VERSION 3.10)

project(binary_tree_serialization)

include_directories($HOME/benchmark/googletest/googletest/include)
include_directories($HOME/benchmark/include)

add_executable (binary_tree_serialization test.cpp)

target_link_libraries (binary_tree_serialization gtest)
target_link_libraries (binary_tree_serialization benchmark)
target_link_libraries (binary_tree_serialization pthread)
