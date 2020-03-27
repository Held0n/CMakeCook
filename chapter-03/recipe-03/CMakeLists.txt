cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-03 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MIN} EXACT REQUIRED)

execute_process(
    COMMAND
        ${PYTHON_EXECUTABLE} "-c" "import re, numpy; print(re.compile('/__init__.py.*').sub('',numpy.__file__))"
    RESULT_VARIABLE _numpy_status
    OUTPUT_VARIABLE _numpy_location
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 如果找到`NumPy`，则`_numpy_status`为整数，否则为错误的字符串
# `numpy_location`包含`NumPy`的路径
if(NOT _numpy_status)
    set(NumPy ${_numpy_location} CACHE STRING "Location of NumPy")
endif()

# 检查模块的版本
execute_process(
  COMMAND
  	${PYTHON_EXECUTABLE} "-c" "import numpy; print(numpy.__version__)"
  OUTPUT_VARIABLE _numpy_version
  ERROR_QUIET
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Numpy
    FOUND_VAR NUMPY_FOUND
    REQUIRED_VARS Numpy
    VERSION_VAR _numpy_version
)

add_executable(pure-embedding "")

target_sources(pure-embedding
  PRIVATE
  	Py${PYTHON_VERSION_MAJOR}_pure_embedding.cpp
  )
  
target_include_directories(pure-embedding
  PRIVATE
  	${PYTHON_INCLUDE_DIRS}
  )
  
target_link_libraries(pure-embedding
  PRIVATE
  	${PYTHON_LIBRARIES}
  )


add_custom_command(
  OUTPUT
  	${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  COMMAND
  	${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
    ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  DEPENDS
  	${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
  )

target_sources(pure-embedding
  PRIVATE
  	${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  )