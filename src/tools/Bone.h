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

    glm::mat4 Bind_coord,world_mat,bind_local,transform;

    int parent;

    Bone(int ID){
        this->ID = ID;

        Bind_coord = glm::mat4(1.0);
        world_mat = glm::mat4(1.0);
        transform = glm::mat4(1.0);
        bind_local = glm::mat4(0);

    }

    Bone(int ID, int parent){
        this->ID = ID;
        this->parent = parent;
        Bind_coord = glm::mat4(1.0);
        world_mat = glm::mat4(1.0);
        transform = glm::mat4(1.0);

    }


};


#endif //OPENGLRENDU_BONE_H
