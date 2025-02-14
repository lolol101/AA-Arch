cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(../util tasks/ template/include/ 
                    ../third_party/json/include/ ../third_party/benchmark/include)

add_executable(Benchmark
    template/src/benchAlgorithm.cpp
    template/src/runScenario.cpp
    template/src/benchmark.cpp
    main.cpp
    )

target_link_libraries(Benchmark PRIVATE StringLib)
target_link_libraries(Benchmark PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Benchmark PRIVATE Util)
target_link_libraries(Benchmark PRIVATE benchmark::benchmark_main)
