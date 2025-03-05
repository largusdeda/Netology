cmake_minimum_required(VERSION 3.12.0)

project(homework2_10_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
	sources/homework2_10_2.cpp
	sources/print_info.cpp
	sources/figure.cpp
	sources/triangle.cpp
	sources/right_triangle.cpp
	sources/isos_triangle.cpp
	sources/eq_triangle.cpp
	sources/quadrangle.cpp
	sources/parallelogram.cpp
	sources/rectangle.cpp
	sources/rhombus.cpp
	sources/square.cpp
)

set(HEADERS
	sources/headers/figure.h
	sources/headers/triangle.h
	sources/headers/right_triangle.h
	sources/headers/isos_triangle.h
	sources/headers/eq_triangle.h
	sources/headers/quadrangle.h
	sources/headers/parallelogram.h
	sources/headers/rectangle.h
	sources/headers/rhombus.h
	sources/headers/square.h
)

add_executable(homework2_10_2 ${SOURCES} ${HEADERS})
