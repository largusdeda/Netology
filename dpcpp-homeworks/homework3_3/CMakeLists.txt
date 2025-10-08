cmake_minimum_required(VERSION 3.22.0)

project("homework3.3" LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()


add_executable(${PROJECT_NAME} "main.cpp" "Logger.h" "Logger.cpp" "LogMessage.h" "LogMessage.cpp" "Handler.h" "Handler.cpp" "FE_Handler.h" "FE_Handler.cpp" "E_Handler.h" "E_Handler.cpp" "W_Handler.h" "W_Handler.cpp" "U_Handler.h" "U_Handler.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)