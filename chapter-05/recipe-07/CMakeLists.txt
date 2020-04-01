cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-07 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CXX_BASIC_FLAGS "-g3" "-O1")
message(STATUS ${CXX_BASIC_FLAGS})
# 需要`CheckCXXCompilerFlag.cmake`模块
include(CheckCXXCompilerFlag)

# 声明一个`asan_flags`变量，`Sanitizer`所需的标志
# 并设置`CMAKE_REQUIRED_FLAGS`
set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")

set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
set(CMAKE_REQUIRED_FLAGS ${ASAN_FLAGS})

check_cxx_compiler_flag(${ASAN_FLAGS} asan_works)
unset(CMAKE_REQUIRED_FLAGS)

if(asan_works)
    # 如果编译器理解这些选项，将变量转换为一个列表，用分号替换空格
    # string(REPLACE " " ";" _asan_flags ${ASAN_FLAGS})
    set(_asan_flags ${ASAN_FLAGS})
    message(STATUS ${_asan_flags})

    add_executable(asan_example asan_example.cpp)

    #为可执行文件设置编译器标志
    target_compile_options(
        asan_example 
        PUBLIC
            ${CXX_BASIC_FLAGS}
            ${_asan_flags}
    )

    target_link_libraries(asan_example PUBLIC ${_asan_flags})
endif()
