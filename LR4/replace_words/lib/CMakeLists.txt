CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

PROJECT (replace_words_shared_library)
SET(CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/include)

ADD_LIBRARY(
        replace_words_shared_library
        SHARED
        src/convert_text.cpp
        src/data_reader.cpp
        src/utils.cpp
)
