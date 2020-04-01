cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(recipe-06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP)

if(OpenMP_FOUND)
    # 设置一个临时目录
    set(_scratch_dir ${CMAKE_CURRENT_BINARY_DIR}/omp_try_compile)
    # 调用`try_compile`生成一个小项目，尝试编译源文件`task_loop.cpp`
    # 编译成功或失败的状态将保存到`omp_taskloop_test_1`变量中
    try_compile(
        omp_taskloop_test_1
            ${_scratch_dir}
        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/taskloop.cpp
        LINK_LIBRARIES
            OpenMP::OpenMP_CXX
    )
    message(STATUS "Result of try_compile: ${omp_taskloop_test_1}")
    # 要使用`check_cxx_source_compiles`函数，需要包含`CheckCXXSourceCompiles.cmake`模块文件
    include(CheckCXXSourceCompiles)
    # 复制源文件的内容，读取源文件内容到一个变量中
    file(READ ${CMAKE_CURRENT_SOURCE_DIR}/taskloop.cpp _snippet)
    # 设置`CMAKE_REQUIRED_LIBRARIES`
    set(CMAKE_REQUIRED_LIBRARIES OpenMP::OpenMP_CXX)
    # 使用代码片段作为参数，调用`check_cxx_source_compiles`函数，将结果保存到`omp_taskloop_test_2`变量中
    check_cxx_source_compiles("${_snippet}" omp_taskloop_test_2)
    # 打印消息前，取消变量的设置
    unset(CMAKE_REQUIRED_LIBRARIES)
    message(STATUS "Result of check_cxx_source_compiles: ${omp_taskloop_test_2}")
else()
    message(STATUS "OpenMP not found: no test for taskloop is run")
endif()

# `try_compile`和`check_cxx_source_compiles`都将编译源文件，并将其链接到可执行文件中
# 如果操作成功`omp_taskloop_test_1`和`omp_taskloop_test_2`将被设置为`TRUE`
# `check_<lang>_source_compiles`是`try_compile`的简化包装