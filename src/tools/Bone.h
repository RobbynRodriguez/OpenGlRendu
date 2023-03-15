//
// Created by robbyn on 14/03/23.
//

#ifndef OPENGLRENDU_BONE_H
#define OPENGLRENDU_BONE_H


#include <glm/glm.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

using namespace glm;
using namespace std;

class Bone {
public:
    int ID;

    glm::vec3 pos;

    glm::mat4 Bind,world_mat,bind_local,local,transform;

    Bone *parent;

    Bone(int ID){
        this->ID = ID;

        Bind = glm::mat4(1.0);
        world_mat = glm::mat4(1.0);
        local = glm::mat4(1.0);
        bind_local = glm::mat4(1.0);

        this->parent = nullptr;

    }

    Bone(int ID, Bone *parent){
        this->ID = ID;
        this->parent = parent;
        Bind = glm::mat4(1.0);
        world_mat = glm::mat4(1.0);
        local = glm::mat4(1.0);

    }



    void set_rest_pos(vec3 pos){
        this->pos = pos;
        this->bind_local = glm::translate(mat4(1.0f),pos);
    }


};


#endif //OPENGLRENDU_BONE_H
