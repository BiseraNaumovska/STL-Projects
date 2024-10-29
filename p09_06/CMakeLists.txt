cmake_minimum_required(VERSION 3.16)

project(p09_06 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p09_06 main.cpp)

include(GNUInstallDirs)
install(TARGETS p09_06
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
