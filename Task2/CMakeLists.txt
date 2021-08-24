cmake_minimum_required(VERSION 3.20)
project(Task2)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Question1a questionOneA.cpp)
add_executable(Question1b questionOneB.cpp)
add_executable(Question4 questionFour.cpp)
add_executable(Question5 questionFive.cpp)
add_executable(Question6 questionSix.cpp)
