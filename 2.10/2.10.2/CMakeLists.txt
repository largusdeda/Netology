cmake_minimum_required(VERSION 3.12.0)

project(homework2_10_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SOURCES "sources/*.cpp")

add_executable(homework2_10_2 ${SOURCES})
target_include_directories(homework2_10_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources/headers)
