cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-1.8 LANGUAGES CXX)

message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
    list(APPEND flags "-Wextra" "-Wpedantic")
endif(NOT WIN32)

add_library(
    geometry
    STATIC
    geometry_circle.cpp
    geometry_circle.hpp
    geometry_polygon.cpp
    geometry_polygon.hpp
)

# 设置编译选项
# PRIVATE: 即使 computer_areas 链接到 geometry 库中，也不会
# 继承 geometry 设置的编译器选项
target_compile_options(
    geometry
    PRIVATE
    ${flags}
)

add_library(computer_area computer_area.cpp)
target_compile_options(computer_area PRIVATE "-fPIC")
target_link_libraries(computer_area geometry)