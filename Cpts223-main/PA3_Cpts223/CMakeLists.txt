cmake_minimum_required(VERSION 3.23)
project(PA3_Cpts223)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(PA3_Cpts223 main.cpp Hash.h ChainingHash.h ProbingHash.h)

