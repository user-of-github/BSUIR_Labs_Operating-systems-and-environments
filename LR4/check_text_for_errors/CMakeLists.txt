cmake_minimum_required(VERSION 3.24)
project(check_text_for_errors)

set(CMAKE_CXX_STANDARD 23)

add_executable(check_text_for_errors main.cpp ./errors_checker/errors_checker.cpp ./errors_checker/errors_checker.hpp utils/utils.cpp utils/utils.hpp data_reader/data_reader.cpp data_reader/data_reader.hpp)
