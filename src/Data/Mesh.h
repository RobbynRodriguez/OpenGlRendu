//
// Created by robbyn on 14/02/2022.
//
#include <GLFW\glfw3.h>

#ifndef OPENGLRENDU_MESH_H
#define OPENGLRENDU_MESH_H


class Mesh {
public:
    Mesh(float *vertices, int *faces);

    float *getVertices() const;

    int *getFaces() const;

private:

    float* vertices;
    int* faces;



};

Mesh::Mesh(float *vertices, int *faces) : vertices(vertices), faces(faces) {}


#endif //OPENGLRENDU_MESH_H
