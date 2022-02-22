cmake_minimum_required(VERSION 3.21)
project(OpenGlRendu)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(LIBS glfw GLU X11 Xrandr pthread)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(X11 REQUIRED)

FILE(GLOB_RECURSE
        folder_source
        ${CMAKE_SOURCE_DIR}/src/*.cpp
        ${CMAKE_SOURCE_DIR}/src/*.c
        )

FILE(GLOB_RECURSE
        folder_header
        ${CMAKE_SOURCE_DIR}/src/*.h

        )

include_directories(
        includes/glad
        includes/KHR
)

add_executable(helloWindow ${folder_source} ${folder_header} src/Shader.cpp src/Shader.h)

target_link_libraries(helloWindow ${LIBS} ${CMAKE_DL_LIBS})