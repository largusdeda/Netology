cmake_minimum_required(VERSION 3.12.0)

project(homework2_11_5 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(LIB_SOURCES 
	FiguresLib/sources/print_info.cpp
	FiguresLib/sources/figure.cpp
	FiguresLib/sources/triangle.cpp
	FiguresLib/sources/right_triangle.cpp
	FiguresLib/sources/isos_triangle.cpp
	FiguresLib/sources/eq_triangle.cpp
	FiguresLib/sources/quadrangle.cpp
	FiguresLib/sources/parallelogram.cpp
	FiguresLib/sources/rectangle.cpp
	FiguresLib/sources/rhombus.cpp
	FiguresLib/sources/square.cpp
)

set(LIB_HEADERS
	FiguresLib/sources/headers/figure.h
	FiguresLib/sources/headers/triangle.h
	FiguresLib/sources/headers/right_triangle.h
	FiguresLib/sources/headers/isos_triangle.h
	FiguresLib/sources/headers/eq_triangle.h
	FiguresLib/sources/headers/quadrangle.h
	FiguresLib/sources/headers/parallelogram.h
	FiguresLib/sources/headers/rectangle.h
	FiguresLib/sources/headers/rhombus.h
	FiguresLib/sources/headers/square.h
)

add_library(FiguresLib SHARED ${LIB_SOURCES} ${LIB_HEADERS})

add_executable(homework2_11_5 source.cpp)
target_link_libraries(homework2_11_5 FiguresLib)