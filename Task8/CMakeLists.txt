cmake_minimum_required(VERSION 3.20)
project(Task8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(QOne QuestionOne/main.cpp)
add_executable(QTwo QuestionTwo/main.cpp)
