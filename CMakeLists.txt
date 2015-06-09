cmake_minimum_required(VERSION 3.2)
project(poo_proiect)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

set(SOURCE_FILES main.cpp)
add_executable(poo_proiect ${SOURCE_FILES} Matrix.cpp Matrix.h)
