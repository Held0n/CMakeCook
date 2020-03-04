cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-1.4 LANGUAGES CXX)

option(USE_LIBRARY "Compile sources into a library" OFF)
message(STATUS "Compile sources into a library ${USE_LIBRARY}")

# BUILD_SHARED_LIBRARY 是一个全局变量
set(BUILD_SHARED_LIBRARY OFF)
list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
    add_library(message ${_sources})
    add_executable(hello_world hello_world.cpp)
    target_link_libraries(hello_world message)
else()
    add_executable(hello_world hello_world.cpp ${_sources})
endif()
