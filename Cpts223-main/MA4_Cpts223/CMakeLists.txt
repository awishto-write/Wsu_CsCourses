cmake_minimum_required(VERSION 3.16)
project(CPTS_223_MA4)
#project(MA4_Cpts223)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Xpreprocessor -fopenmp -lomp -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib")

add_executable(CPTS_223_MA4 main.cpp)

find_package( OPENMP REQUIRED)
#find_package(OpenMP REQUIRED) # Find the package

#target_link_libraries(CPTS_223_MA4 ${OPENMP_CXX_LIBRARIES}) # Link against it for C++
target_link_libraries(${PROJECT_NAME} ${OpenMP_CXX_LIBRARIES}) # Link against it for C++



