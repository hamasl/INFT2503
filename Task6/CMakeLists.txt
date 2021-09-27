cmake_minimum_required(VERSION 3.20)
project(Task6)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

find_package(Boost 1.76.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


add_executable(QOne QuestionOne/main.cpp)
add_executable(QTwo QuestionTwo/main.cpp)
target_link_libraries(QTwo ${Boost_LIBRARIES})