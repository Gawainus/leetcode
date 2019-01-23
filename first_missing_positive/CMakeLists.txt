cmake_minimum_required(VERSION 3.10)

project(first_missing_positive)

include_directories($HOME/benchmark/googletest/googletest/include)
include_directories($HOME/benchmark/include)

add_executable (first_missing_positive test.cpp)

target_link_libraries (first_missing_positive gtest)
target_link_libraries (first_missing_positive benchmark)
target_link_libraries (first_missing_positive pthread)
