cmake_minimum_required(VERSION 3.16)
project(StaticLib)

set(CMAKE_CXX_STANDARD 17)

ADD_LIBRARY( StaticLib STATIC ./convert_text/convert_text.cpp ./data_reader/data_reader.cpp ./utils/utils.cpp )
