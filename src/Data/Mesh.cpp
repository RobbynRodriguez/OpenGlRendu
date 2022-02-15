//
// Created by robbyn on 14/02/2022.
//

#include "Mesh.h"

Mesh::Mesh(float *vertices, int faces[]) : vertices(vertices), faces(faces) {}

int *Mesh::getFaces() const {
    return faces;
}

float *Mesh::getVertices() const {
    return vertices;
}


