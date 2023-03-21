CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(libs_combination)

SET(CMAKE_CXX_STANDARD 20)

ADD_EXECUTABLE(libs_combination main.cpp ./external_libs/errors_checker.a)

#TARGET_LINK_LIBRARIES(libs_combination ./external_libs/errors_checker.a)

