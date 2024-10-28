cmake_minimum_required(VERSION 3.16)

project(p02_10 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(p02_10 main.cpp)

include(GNUInstallDirs)
install(TARGETS p02_10
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
