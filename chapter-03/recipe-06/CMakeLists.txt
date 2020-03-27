cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(recipe-06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(MPI REQUIRED)

include(CMakePrintHelpers)
cmake_print_properties(
	TARGETS
    MPI::MPI_CXX
	PROPERTIES
		INTERFACE_COMPILE_OPTIONS
		INTERFACE_INCLUDE_DIRECTORIES
		INTERFACE_LINK_LIBRARIES
)

add_executable(hello_mpi hello_mpi.cpp)
target_link_libraries(hello_mpi
  PUBLIC
        MPI::MPI_CXX
)