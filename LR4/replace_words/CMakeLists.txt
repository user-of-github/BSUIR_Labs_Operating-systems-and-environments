cmake_minimum_required(VERSION 3.24)
project(replace_words)

set(CMAKE_CXX_STANDARD 23)

add_executable(replace_words main.cpp data_reader/data_reader.cpp data_reader/data_reader.hpp utils/utils.hpp utils/utils.cpp convert_text/convert_text.cpp convert_text/convert_text.hpp)
