cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-02 LANGUAGES NONE)

find_package(PythonInterp REQUIRED)

# 调用`execute_process`运行一个简短的Python代码
set(_module_name "cffi")

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "import ${_module_name}; print(${_module_name}.__version__)"
    OUTPUT_VARIABLE _stdout
    ERROR_VARIABLE _stderr
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_STRIP_TRAILING_WHITESPACE
)

# 打印结果
if(_stderr MATCHES "ModuleNotFoundError")
    message(STATUS "Module ${_module_name} not found")
else()
    message(STATUS "Found module ${_module_name} v${_stdout}")
endif(_stderr MATCHES "ModuleNotFoundError")

## `execute_process`将从正在执行的CMake进程中派生一个或多个子进程
## `execute_process`有多个参数
## 
## - WORKING_DIRECTORY 指定在哪个目录中执行命令
## - OUTPUT_VARIABLE ERROR_VARIABLE 将包含执行命令的标准输出和标准错误，只有最后一个命令的标准输出会保存
## - INPUT_FILE 指定标准输入重定向的文件名
## - OUTPUT_FILE 指定标准输出重定向的文件名
## - ERROR_FILE 指定标准错误重定向的文件名
## - OUTPUT_QUIET ERROR_QUIET 忽略标准输出和标准错误
## - OUTPUT_STRIP_WHITESPACE 删除运行命令的标准输出中的任何尾随空格
## - ERROR_STRIP_WHITESPACE 删除运行命令的标准错误中的任何尾随空格
