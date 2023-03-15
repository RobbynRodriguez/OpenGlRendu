//
// Created by robbyn on 15/03/23.
//

#ifndef OPENGLRENDU_VERTEX_H
#define OPENGLRENDU_VERTEX_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

using namespace std;
using namespace glm;

class Vertex {
public:
    // position
    vec3 Position;
    // normal
    vec3 Normal;
    // texCoords
    vec2 TexCoords;

    vector<float> weights;

    Vertex(const vec3 &position, const vec3 &normal, const vec2 &texCoords) : Position(position), Normal(normal),
                                                                                      TexCoords(texCoords) {}
};


#endif //OPENGLRENDU_VERTEX_H
