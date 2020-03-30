cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sum_integers sum_integers.cpp)

add_executable(sum main.cpp)
target_link_libraries(sum sum_integers)

add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test sum_integers)

enable_testing()
# `--success`，是一个Catch2选项，测试成功时，也会有输出
add_test(
    NAME catch_test
    COMMAND $<TARGET_FILE:cpp_test> --success
)