cmake_minimum_required(VERSION 3.20)
project(c_opengl_framework C)

set (SOURCES
    src/main.c src/init.c)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
include_directories(vendor/glad/include vendor/glfw/include)

add_executable(c_opengl_framework ${SOURCES})

target_link_libraries(c_opengl_framework
    glad
    glfw
    )

