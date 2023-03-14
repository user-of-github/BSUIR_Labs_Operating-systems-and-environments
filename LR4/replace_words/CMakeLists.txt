cmake_minimum_required(VERSION 3.24)
project(replace_words)

set(CMAKE_CXX_STANDARD 23)

add_executable(replace_words main.cpp file_reader.cpp file_reader.hpp)
