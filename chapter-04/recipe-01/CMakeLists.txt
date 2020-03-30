cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)

# example library
add_library(sum_integers sum_integers.cpp)

add_executable(sum main.cpp)
target_link_libraries(sum sum_integers)

# test binary
add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test sum_integers)

# enable test 测试这个目录和所有子文件夹
enable_testing()

# 定义了一个新的测试，并设置测试名称和运行命令
add_test(
    NAME cpp_test
    # $<target_file:cpp_test> 生成器表达式
    COMMAND $<TARGET_FILE:cpp_test>
)

add_test(
    NAME python_test_long
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py --executable $<TARGET_FILE:sum>
)

add_test(
    NAME python_test_short
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py --short --executable $<TARGET_FILE:sum>
)