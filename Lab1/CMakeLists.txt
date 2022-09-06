cmake_minimum_required(VERSION 3.23)
project(Lab1)

set(CMAKE_CXX_STANDARD 14)

#include_directories(MyLib) # Расположение заголовочных файлов
add_subdirectory(MyStaticLib) # Добавление подпроекта, указывается имя дирректории

add_executable(Lab1 main.cpp MyStaticLib/image.cpp MyStaticLib/image.h)

target_link_libraries(Lab1 PUBLIC MyStaticLib)

target_include_directories(Lab1 PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/MyStaticLib")