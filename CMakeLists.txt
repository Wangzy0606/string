cmake_minimum_required(VERSION 3.10.0)
project(3string VERSION 0.1.0 LANGUAGES C CXX)

add_executable(3string String.cpp)

include(CTest)
enable_testing()

