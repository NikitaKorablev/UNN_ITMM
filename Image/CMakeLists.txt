cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(Image)

#add_subdirectory(MyStaticLib) # Добавление подпроекта, указывается имя дирректории

#add_executable(Lab2 main.cpp)

#target_link_libraries(Lab2 PRIVATE MyStaticLib)

#target_include_directories(Lab2 PRIVATE
#        "${PROJECT_BINARY_DIR}"
#        "${PROJECT_SOURCE_DIR}/MyStaticLib")

include(function.cmake)

option(BTEST "build test?" ON)

add_subdirectory(Libs/image)
add_subdirectory(Libs/Colorize)

if(BTEST)
    add_subdirectory(Libs/gtest)
    add_subdirectory(Libs/tests)
endif()
unset(BTEST CACHE)

add_subdirectory(main)


