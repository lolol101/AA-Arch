cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

include_directories(include)
include_directories(util)
include_directories(third_party/catch_2/src)
include_directories(third_party/json/include)

# TODO: add flag for test compilation
add_subdirectory(third_party/catch2/)

add_library(StringLib STATIC 
    src/AhoCorasick.cpp
    src/KnuthMorrisPratt.cpp
    src/RabinCarp.cpp
    )

add_library(Util STATIC util/util.cpp)

add_subdirectory(test)
add_subdirectory(benchmark)
