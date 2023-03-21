cmake_minimum_required(VERSION 3.24)
project(combine_libs)

set(CMAKE_CXX_STANDARD 17)

add_executable(combine_libs main.cpp)

target_link_libraries(combine_libs ./libStaticLib.a)