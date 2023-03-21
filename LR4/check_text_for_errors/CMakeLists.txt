cmake_minimum_required(VERSION 3.24)
project(check_text_for_errors)

set(CMAKE_CXX_STANDARD 23)

add_executable(check_text_for_errors main.cpp lib/errors_checker.cpp lib/include/errors_checker.hpp lib/utils.cpp lib/include/utils.hpp lib/data_reader.cpp lib/include/data_reader.hpp)
