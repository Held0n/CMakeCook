cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-04 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sum_integers sum_integers.cpp)
add_executable(sum main.cpp)

target_link_libraries(sum sum_integers)

find_package(Boost 1.72 REQUIRED COMPONENTS unit_test_framework)
add_executable(cpp_test test.cpp)

target_link_libraries(
    cpp_test
    PRIVATE
    sum_integers
    Boost::unit_test_framework
)

target_compile_definitions(
    cpp_test
    PRIVATE
    BOOST_TEST_DYN_LINK
)

enable_testing()
add_test(
    NAME boost_test
    COMMAND $<TARGET_FILE:cpp_test>
)