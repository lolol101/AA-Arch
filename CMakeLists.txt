cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(include)
include_directories(third_party/catch_2/src)

# TODO: add flag for test compilation
add_subdirectory(third_party/catch2/)

add_library(StringLib STATIC src/algorithm.cpp)
add_executable(Test test/test.cpp)

target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
