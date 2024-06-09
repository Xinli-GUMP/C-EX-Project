cmake_minimum_required(VERSION 3.27.5)

# 设置项目名称以及使用的C++标准
project(Employee_management_system VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_definitions(-std=c++17)
add_compile_definitions(_UNICODE UNICODE) # 确保了程序在处理字符串时默认使用Unicode而非ANSI。

# 添加 include 目录
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(F:/Documents/C++/include)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
# 从列表中移除 test.cpp
list(REMOVE_ITEM SRC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/test.cpp")
# 添加特定的源文件
list(APPEND SRC_LIST "F:/Documents/C++/include/myhead.hpp")

# 指定生成目标
add_executable(Employee_management_system ${SRC_LIST})
#指示编译器假设源文件使用UTF-8编码格式
target_compile_options(Employee_management_system PRIVATE -finput-charset=UTF-8)

# 如果有需要链接的库，使用target_link_libraries
# target_link_libraries(Employee_management_system other_libs)
