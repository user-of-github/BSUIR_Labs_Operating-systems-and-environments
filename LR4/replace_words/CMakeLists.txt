cmake_minimum_required(VERSION 3.16)
project(replace_words)

set(CMAKE_CXX_STANDARD 17)

add_executable(replace_words main.cpp lib/data_reader/data_reader.cpp lib/data_reader/data_reader.hpp lib/utils/utils.hpp lib/utils/utils.cpp lib/convert_text/convert_text.cpp lib/convert_text/convert_text.hpp)
