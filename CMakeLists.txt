cmake_minimum_required(VERSION 3.16)
project(OpenGlRendu)

set(CMAKE_CXX_STANDARD 20)

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
        includes/glm
        includes/ImGui
        includes
)

add_executable(helloWindow ${folder_source} ${folder_header} includes/stb_image.h includes/stb_image.cpp includes/stb_image.h src/tools/camera.h src/Data/Mesh.h src/Data/BezierCurve.h src/Data/BezierSurface.h src/tools/Lights.h src/Data/Model.h src/tools/Bone.cpp src/tools/Bone.h)

target_link_libraries(helloWindow ${LIBS} ${CMAKE_DL_LIBS})