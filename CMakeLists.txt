# 设置 CMake 的最低版本要求为 3.10
cmake_minimum_required(VERSION 3.10)

# 设置项目名称为 StringProject
project(StringProject)

# 设置 C++ 标准为 C++11
set(CMAKE_CXX_STANDARD 11)

# 包含 include 目录，让编译器能找到头文件
include_directories(include)

# 添加可执行文件 StringProject，指定源文件为 string_main.cpp 和 string_functions.cpp
add_executable(StringProject 
    src/string_main.cpp
    src/string_functions.cpp
)    