cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(recipe-05 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

include(CMakePrintHelpers)
cmake_print_properties(
	TARGETS
		OpenMP::OpenMP_CXX
	PROPERTIES
		INTERFACE_COMPILE_OPTIONS
		INTERFACE_INCLUDE_DIRECTORIES
		INTERFACE_LINK_LIBRARIES
)

add_executable(example example.cpp)
target_link_libraries(example
  PUBLIC
  OpenMP::OpenMP_CXX
)