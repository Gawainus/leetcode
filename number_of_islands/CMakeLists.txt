cmake_minimum_required(VERSION 3.10)

project(number_of_islands)

include_directories($HOME/benchmark/googletest/googletest/include)
include_directories($HOME/benchmark/include)

add_executable (number_of_islands test.cpp)

#target_link_libraries (number_of_islands LINK_PUBLIC Hello)
