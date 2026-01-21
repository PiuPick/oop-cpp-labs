cmake_minimum_required(VERSION 4.1)
project(oop-cpp-labs)

set(CMAKE_CXX_STANDARD 17)

# Лабораторная работа 1
add_executable(lab1 lab1/main.cpp)

# Лабораторная работа 2
add_executable(lab2 lab2/source.cpp lab2/matrix.cpp)

# Лабораторная работа 3
add_executable(lab3 lab3/main.cpp lab3/src/Functions.cpp lab3/src/Tests.cpp)