cmake_minimum_required(VERSION 3.12.0)
project(homework2_10_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

add_executable(my_first_cmake_project source.cpp)
