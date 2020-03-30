cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-10 LANGUAGES CXX)

find_package(PythonInterp REQUIRED)

enable_testing()
add_test(
    NAME setup
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/setup.py
)

set_tests_properties(
    setup PROPERTIES FIXTURES_SETUP my-fixture
)

add_test(
    NAME features-a
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/features-a.py
)
add_test(
    NAME features-b
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/features-b.py
)

set_tests_properties(
    features-a features-b
    PROPERTIES FIXTURES_REQUIRED my-fixture
)

add_test(
    NAME cleanup
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test/cleanup.py
)

set_tests_properties(
    cleanup
    PROPERTIES FIXTURES_CLEANUP my-fixture
)