cmake_minimum_required(VERSION 3.21)
project(OpenGlRendu)

set(CMAKE_CXX_STANDARD 23)

add_executable(OpenGlRendu main.cpp src/Data/Mesh.cpp src/Data/Mesh.h src/Data/BezierCurve.cpp src/Data/BezierCurve.h src/Data/TriangleMesh.cpp src/Data/TriangleMesh.h src/OpenGl/Drawable.cpp src/OpenGl/Drawable.h src/OpenGl/Program.cpp src/OpenGl/Program.h)
