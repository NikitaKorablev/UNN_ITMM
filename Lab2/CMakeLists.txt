cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(Lab2)

#add_subdirectory(MyStaticLib) # Добавление подпроекта, указывается имя дирректории

#add_executable(Lab2 main.cpp)

#target_link_libraries(Lab2 PRIVATE MyStaticLib)

#target_include_directories(Lab2 PRIVATE
#        "${PROJECT_BINARY_DIR}"
#        "${PROJECT_SOURCE_DIR}/MyStaticLib")


include(cmake/function.cmake)

add_subdirectory(MyStaticLib)
add_subdirectory(main)


