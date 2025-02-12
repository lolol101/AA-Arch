cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(../test/template/include ../test/util tasks/ template/include/)

add_executable(Benchmark
    tasks/benchKnuthMorrisPratt.cpp
    template/src/benchAlgorithm.cpp
    template/src/runScenario.cpp
    )

target_link_libraries(Benchmark PRIVATE StringLib)
target_link_libraries(Benchmark PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Benchmark PRIVATE Util)
