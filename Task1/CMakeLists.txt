cmake_minimum_required(VERSION 3.20)
project(Task1)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

file(COPY "temperatures.txt" DESTINATION "../cmake-build-debug")

add_executable(Task1 main.cpp)