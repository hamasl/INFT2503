cmake_minimum_required(VERSION 3.20)
project(Task10)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-reorder -Wno-ignored-qualifiers")

configure_file(${PROJECT_SOURCE_DIR}/imgui-sfml/imconfig-SFML.h ${PROJECT_SOURCE_DIR}/imgui/imconfig.h COPYONLY)

if(APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
endif()

find_package(SFML 2.1 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIR})

find_package(Bullet REQUIRED)
include_directories(${BULLET_INCLUDE_DIRS})

find_package(Threads REQUIRED)

include_directories(imgui imgui-sfml)

add_executable(Task10 main.cpp glut_shapes.c imgui/imgui.cpp imgui/imgui_widgets.cpp imgui/imgui_draw.cpp imgui-sfml/imgui-SFML.cpp)

target_link_libraries(Task10 ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(Task10 ${SFML_LIBRARIES})
target_link_libraries(Task10 ${OPENGL_LIBRARIES})
target_link_libraries(Task10 ${BULLET_LIBRARIES})

