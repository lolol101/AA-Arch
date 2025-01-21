cmake_minimum_required(VERSION 3.15) # Минимальная версия CMake для поддержки современных функций
project(TestProject)

set(CMAKE_CXX_STANDARD 17) # Укажите стандарт C++

add_executable(Test src/test.cpp)
include_directories(./third_party/catch2)

find_package(Catch2 REQUIRED)
target_link_libraries(Test PRIVATE Catch2::Catch2)

enable_testing()

add_test(NAME MyTest COMMAND Test)
