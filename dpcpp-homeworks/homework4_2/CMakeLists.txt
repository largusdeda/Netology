cmake_minimum_required(VERSION 3.22.0)

project("homework4.2" LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

include_directories(include)

add_executable(${PROJECT_NAME} 
    include/printable.h 
    include/html_data.h
    include/text_data.h
    include/json_data.h
    include/save_to.h

    src/main.cpp 
    src/html_data.cpp
    src/text_data.cpp
    src/json_data.cpp
    src/save_to.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)