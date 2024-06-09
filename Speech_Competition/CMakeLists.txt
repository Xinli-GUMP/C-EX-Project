cmake_minimum_required(VERSION 3.27.5)
project(Spech_Competition VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-std=c++20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(_UNICODE UNICODE) # 确保了程序在处理字符串时默认使用Unicode而非ANSI。

# 添加 include 目录
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(F:/Documents/C++/include/)

# 设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 查找目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(Spech_Competition ${SRC_LIST})
target_compile_options(Spech_Competition PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8 )

# 确保您在项目的顶层CMakeLists.txt文件中调用了 enable_testing()，并且是在任何 add_subdirectory() 调用添加测试子目录之前。
enable_testing()

# 添加子目录
add_subdirectory(tests bin)



