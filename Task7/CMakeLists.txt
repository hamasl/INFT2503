cmake_minimum_required(VERSION 3.20)
project(Task7)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(QOne QuestionOne/main.cpp QuestionOne/fraction.cpp)
add_executable(QTwo QuestionTwo/main.cpp QuestionTwo/set.cpp)
