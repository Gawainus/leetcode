cmake_minimum_required(VERSION 3.10)

project(integer_partition)

include_directories($HOME/benchmark/googletest/googletest/include)
include_directories($HOME/benchmark/include)

add_executable (integer_partition test.cpp)

target_link_libraries (integer_partition gtest)
target_link_libraries (integer_partition benchmark)
target_link_libraries (integer_partition pthread)
