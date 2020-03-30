cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-07 LANGUAGES NONE)

find_package(PythonInterp REQUIRED)
enable_testing()
add_test(
    example
    ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py
)

set_tests_properties(
    example
    PROPERTIES TIMEOUT 10
)