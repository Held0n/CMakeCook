cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-08 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.72 REQUIRED COMPONENTS filesystem)
add_executable(path_info path_info.cpp)
target_link_libraries(path_info PUBLIC Boost::filesystem)