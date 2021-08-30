cmake_minimum_required(VERSION 3.20)
project(Task3)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )


add_executable(Circles QuestionOne/Circle.cpp)
add_executable(QuestionTwo QuestionTwo/main.cpp)
add_executable(QuestionThree QuestionThree/main.cpp)
add_executable(QuestionFour QuestionFour/main.cpp)
add_executable(Comm QuestionThree/Commodity.cpp)
