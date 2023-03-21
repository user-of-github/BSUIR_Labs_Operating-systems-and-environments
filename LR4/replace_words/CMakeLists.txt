cmake_minimum_required(VERSION 3.16)
project(replace_words)

set(CMAKE_CXX_STANDARD 17)

add_executable(replace_words main.cpp lib/src/data_reader.cpp lib/include/data_reader.hpp lib/include/utils.hpp lib/src/utils.cpp lib/src/convert_text.cpp lib/include/convert_text.hpp)
