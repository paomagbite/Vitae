######################################################################
# @author      : Dbeela (paomagbite@gmail.com)
# @file        : CMakeLists
# @created     : Monday Nov 08, 2021 17:06:22 HKT
######################################################################

cmake_minimum_required(VERSION "3.21.3")
project(Viate VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCE_FILES src/*.cpp)
 
add_executable(Vitae ${SOURCE_FILES})

