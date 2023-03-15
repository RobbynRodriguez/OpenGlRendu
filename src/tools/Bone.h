//
// Created by robbyn on 14/03/23.
//

#ifndef OPENGLRENDU_BONE_H
#define OPENGLRENDU_BONE_H


#include <glm/fwd.hpp>
#include <glm/detail/type_mat4x4.hpp>

class Bone {
public:
    int ID;

    glm::vec4 coord;

    glm::mat4 Bind_coord = glm::mat4(1);
    glm::mat4 transfo;

    glm::mat4 translation,rotation,scale;

    int parent;

    Bone(int ID){
        this->ID = ID;
    }

    Bone(int ID, int parent){
        this->ID = ID;
        this->parent = parent;
    }

};


#endif //OPENGLRENDU_BONE_H
