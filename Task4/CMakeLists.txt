cmake_minimum_required(VERSION 3.20)
project(Task4)

set(CMAKE_CXX_STANDARD 20)

INCLUDE(FindPkgConfig)

if(APPLE)
    set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/local/lib/pkgconfig:/opt/X11/lib/pkgconfig:/usr/local/Cellar/libffi/3.2.1/lib/pkgconfig:/usr/local/Cellar/libsigc++@2/2.10.2/lib/pkgconfig")
endif()

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})


add_executable(QOne QuestionOne/main.cpp)
add_executable(QTwo QuestionTwo/main.cpp)
target_link_libraries(QTwo ${GTKMM_LIBRARIES})
