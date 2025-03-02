cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(BENCHMARK_ENABLE_TESTING OFF)

include_directories(include)
include_directories(util)
include_directories(third_party/catch_2/include)
include_directories(third_party/json/include)
include_directories(third_party/benchmark/include)

# TODO: add flag for test compilation
add_subdirectory(third_party/catch2/)
add_subdirectory(third_party/benchmark/)

add_library(StringLib STATIC 
    src/AhoCorasick.cpp
    src/BoyerMoore.cpp
    src/KnuthMorrisPratt.cpp
    src/RabinCarp.cpp
    src/LCS.cpp
    )

add_library(Util STATIC util/util.cpp)

add_subdirectory(test)
add_subdirectory(benchmark)
