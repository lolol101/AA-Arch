cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch1 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(./)

add_executable(Test 
    test_suites/corner_case/testAhoCorasickCorner.cpp
    test_suites/random/testAhoCorasickRandom.cpp
    )

target_link_libraries(Test PRIVATE StringLib)
target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Test PRIVATE Util)
