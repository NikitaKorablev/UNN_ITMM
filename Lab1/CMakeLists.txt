cmake_minimum_required(VERSION 3.23)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(MyStaticLib) # Добавление подпроекта, указывается имя дирректории

add_executable(Lab1 main.cpp)

target_link_libraries(Lab1 PRIVATE MyStaticLib)

target_include_directories(Lab1 PRIVATE
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/MyStaticLib")