cmake_minimum_required(VERSION 3.10)

project(longest_substring_wo_repeating_char)

include_directories($HOME/benchmark/googletest/googletest/include)
include_directories($HOME/benchmark/include)

add_executable (longest_substring_wo_repeating_char test.cpp)

target_link_libraries (longest_substring_wo_repeating_char gtest)
target_link_libraries (longest_substring_wo_repeating_char benchmark)
target_link_libraries (longest_substring_wo_repeating_char pthread)
