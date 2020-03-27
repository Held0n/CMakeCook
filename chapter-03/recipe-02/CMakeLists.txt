cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-02 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_STANDARD_REQUIRED ON)

# 找到 Python解释器，这是一个`REQUIRED`
find_package(PythonInterp REQUIRED)

# 找到Python头文件和库的模块，称为`FindPythonLibs.cmake`
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

add_executable(hello_embedded_python hello_embedded_python.c)

# 可执行文件包含`Python.h`头文件。
# 因此`target`的`include`目录必须包含Python的`include`目录
target_include_directories(hello_embedded_python
    PRIVATE
        ${PYTHON_INCLUDE_DIR}
)

target_link_libraries(hello_embedded_python
    PRIVATE
        ${PYTHON_LIBRARIES}
)
