# set minmum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(recipe-10 LANGUAGES CXX)

add_library(
    geometry
    STATIC
    geometry_circle.cpp
    geometry_circle.hpp
    geometry_polygon.cpp
    geometry_polygon.hpp
)

# compile with the flags -O3
target_compile_options(
    geometry
    PRIVATE
    -O3
)

list(
    APPEND source_with_lower_optimization
    geometry_circle.cpp
)

# use the IN LISTS foreach syntax to set source properties
message(STATUS "Setting source properties using IN LISTS syntax:")
foreach(_source IN LISTS source_with_lower_optimization)
    set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
    message(STATUS "Appending -O2 flag for ${_source}")
endforeach()

message(STATUS "Querying sources properties using plain syntax:")
foreach(_source ${source_with_lower_optimization})
    get_source_file_property(_flags ${_source} COMPILE_FLAGS)
    message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach()

add_executable(compute_areas compute_areas.cpp)

target_link_libraries(compute_areas geometry)