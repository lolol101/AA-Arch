cmake_minimum_required(VERSION 3.2.0)
project(AA-Arch VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(include)
add_subdirectory(test)

add_library(StringLib STATIC src/algorithm.cpp)