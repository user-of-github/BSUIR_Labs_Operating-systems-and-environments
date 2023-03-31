CMAKE_MINIMUM_REQUIRED(VERSION 3.9)
PROJECT(libs_combination)

SET(CMAKE_CXX_STANDARD 20)

# For access to standard installation directory variables (CMAKE_INSTALL_xDIR).

include(GNUInstallDirs)
# Set library shared object and API header file to install.
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )

ADD_EXECUTABLE(libs_combination main.cpp external_libs/static/errors_checker.a)

#TARGET_LINK_LIBRARIES(libs_combination external_libs/shared/libreplace_words_shared.so)


#TARGET_LINK_LIBRARIES(libs_combination ./external_libs/errors_checker.a)

