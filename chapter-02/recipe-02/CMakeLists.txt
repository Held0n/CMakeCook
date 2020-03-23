cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-02 LANGUAGES CXX)

add_executable(hello_world hello_world.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(hello_world PUBLIC "IS_LINUX")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(hello_world PUBLIC "IS_DARWIN")
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(hello_world PUBLIC "IS_WINDOWS")
endif()

