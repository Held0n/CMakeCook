cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-04 VERSION 2.0.1 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

configure_file(
    version.h.in
    generated/version.h
    @ONLY
)

add_executable(example example.c)
target_include_directories(
    example
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}/generated
)