cmake_minimum_required(VERSION 3.1.0)
project(utils)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CMAKE_CXX_STANDARD 11)
add_compile_definitions(UTILS_LOADABLE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(utils SHARED
        Utils_global.h
        Utils.cpp
        Utils.h
        )

target_link_libraries(utils PUBLIC Qt5::Widgets)
target_compile_definitions(utils PUBLIC UTILS_LIBRARY)

install(TARGETS utils
        LIBRARY DESTINATION lib/carpi)
