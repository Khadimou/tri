cmake_minimum_required(VERSION 3.13.4)
project(test VERSION 1.0 LANGUAGES CXX)

#compilation c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tri triabulle.cpp)
add_executable(rapide tri_rapide.cpp)
