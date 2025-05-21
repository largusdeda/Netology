cmake_minimum_required(VERSION 3.22.0)

project(smart_array LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(lib SHARED
			lib/smart_array.h
			lib/smart_array.cpp
			lib/array_ex.h
			lib/array_ex.cpp
)

include_directories(lib)

add_executable(SmartArray main.cpp)
target_link_libraries(SmartArray lib)