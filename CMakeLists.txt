cmake_minimum_required (VERSION 3.10)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # require at least gcc 4.8
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 7.0)
        message(FATAL_ERROR "GCC version must be at least 7.0!")
    endif()
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(thirdparty/include)

link_directories(thirdparty/lib)
link_directories(thirdparty/lib64)

add_subdirectory(binary_tree_serialization)
add_subdirectory(first_missing_positive)
add_subdirectory(longest_substring_wo_repeating_char)
add_subdirectory(lru_cache)
add_subdirectory(number_of_islands)
