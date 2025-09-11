cmake_minimum_required(VERSION 3.22.0)

project("homework3.1" LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()


add_executable(${PROJECT_NAME} main.cpp "print.h" "print.cpp" "selectionSort.h" "selectionSort.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)