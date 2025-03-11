cmake_minimum_required(VERSION 3.12.0)

project(homework2_11_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(LeaverDyn SHARED 
	leaving/LeaverDyn/Leaver.h 
	leaving/LeaverDyn/Leaver.cpp)

add_executable(Leaving leaving/leaving.cpp)
target_link_libraries(Leaving LeaverDyn)