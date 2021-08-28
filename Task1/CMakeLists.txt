cmake_minimum_required(VERSION 3.20)
project(Task1)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

# NOTE uncomment and set DESTINATION to build directory be able to copy the temperatures file over to the build directory
# file(COPY "temperatures.txt" DESTINATION "../cmake-build-debug")

add_executable(TaskA a.cpp)
add_executable(TaskB b.cpp)