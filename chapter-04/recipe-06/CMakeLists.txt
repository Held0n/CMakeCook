cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-06 LANGUAGES NONE)
find_package(PythonInterp REQUIRED)

enable_testing()
add_test(
    example
    ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py
)

# 将属性`WILL_FAIL`设置为`true`，这将转换成功和失败
set_tests_properties(
    example
    PROPERTIES WILL_FAIL true
)