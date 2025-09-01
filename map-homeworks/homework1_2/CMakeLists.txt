cmake_minimum_required(VERSION 3.22.0)

project("homework1.2" LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()


add_executable(${PROJECT_NAME} main.cpp "fill_vector.h" "fill_vector.cpp" "multi_sum.h" "multi_sum.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)