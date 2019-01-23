cmake_minimum_required(VERSION 3.10)

project(lru_cache)

include_directories($HOME/benchmark/googletest/googletest/include)
include_directories($HOME/benchmark/include)

add_executable (lru_cache test.cpp)

target_link_libraries (lru_cache gtest)
target_link_libraries (lru_cache benchmark)
target_link_libraries (lru_cache pthread)

add_executable (lru_cache_bm benchmark.cpp)
target_link_libraries (lru_cache_bm benchmark)
target_link_libraries (lru_cache_bm pthread)
