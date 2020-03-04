cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-1.3 LANGUAGES CXX)
add_library(message
  STATIC
    Message.hpp
    Message.cpp
)
add_executable(hello_world hello_world.cpp)
target_link_libraries(hello_world message)