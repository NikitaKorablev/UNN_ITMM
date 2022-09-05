cmake_minimum_required(VERSION 3.23)
project(StaticLib)

set(CMAKE_CXX_STANDARD 14)

#include_directories(MyLib) # Расположение заголовочных файлов
add_subdirectory(MyLib) # Добавление подпроекта, указывается имя дирректории

add_executable(StaticLib main.cpp MyLib/image.cpp MyLib/image.h)

target_link_libraries(StaticLib PUBLIC MyLib)

target_include_directories(StaticLib PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/MyLib")