cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES NONE)

# 使用`find_package`找到python的解释器
find_package(PythonInterp REQUIRED)

# 执行Python命令，并捕获它的输出和返回值
execute_process(
    COMMAND
        ${PYTHON_EXECUTABLE} "-c" "print('Hello, world!')"
    RESULT_VARIABLE _status
    OUTPUT_VARIABLE _hello_world
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "RESULT_VARIABLE is: ${_status}")
message(STATUS "OUTPUT_VARIABLE is: ${_hello_world}")

# `find_package`用于发现和设置包
# Cmake模块文件为`Find<name>.cmake`
# 对于Python解释器，相关模块为`FindPythonInterp.cmake`
# - PYTHONINTERP_FOUND: 是否找到解释器
# - PYTHON_EXECUTABLE: python解释器到可执行文件的路径
# - PYTHON_VERSION_STRING: python解释器的完整版本信息