cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

include_directories(include)
include_directories(util)
include_directories(third_party/catch_2/src)

# TODO: add flag for test compilation
add_subdirectory(third_party/catch2/)

add_library(StringLib STATIC src/AhoCorasick.cpp)
add_executable(Test
            test/corner_case/testAhoCorasickCorner.cpp
            test/random_case/testAhoCorasickStress.cpp
            )

add_executable(Benchmark benchmark/benchmark.cpp)

add_library(Util STATIC util/util.cpp)

target_link_libraries(Test PRIVATE StringLib)
target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Test PRIVATE Util)

target_link_libraries(Benchmark PRIVATE StringLib)
target_link_libraries(Benchmark PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Benchmark PRIVATE Util)
