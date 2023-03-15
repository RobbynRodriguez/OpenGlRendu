//
// Created by robbyn on 15/03/23.
//

#ifndef OPENGLRENDU_SKIN_H
#define OPENGLRENDU_SKIN_H


#include "Bone.h"
#include "../Data/Mesh.h"

class Skin {


public:
    vector<Bone> skeleton;
    Mesh mesh;





    explicit Skin(const vector<Bone> &skeleton, Mesh mesh) : skeleton(skeleton), mesh(mesh) {


    }


    void Linear_skinning(){
        glm::mat4  transfo;
        vector<Vertex> vertices = this->mesh.vertices;


        for(int i = 0; i < this->mesh.vertices.size() ; i++){
            Vertex vertex = vertices[i];
//            std::cout << vertex.weights[0] << std::endl;
            transfo = glm::mat4(1.0f);
            for(int j = 0 ; j< skeleton.size(); j++){
//                std::cout << vertex.weights[j] << std::endl;
                transfo += vertex.weights[j] * skeleton[j].transform;
            }
            vec4 pos = transfo * vec4(vertex.Position,1.0f);
            pos = pos/pos[3];
//            std::cout << pos[0] << pos[1] << pos[2] << std::endl;
            vertex.Position = vec3(pos);
            mesh.vertices[i] = vertex;
        }
        mesh.updateVBO();
    }

    void update_parent(Bone *pBone, mat4 mat1) {
//        pBone->world_mat = mat1 * pBone->pos * pBone->local;

//        pBone->transform = pBone->pos * inverse(pBone->Bind);
//        std::cout << pBone->transform[0][0] << std::endl;

//        if(pBone->parent != nullptr){
//            update_parent(pBone->parent, pBone->world_mat);
//        }

    }

    void rotation(float theta, int ID){
        skeleton[ID].transform = glm::rotate(skeleton[ID].local, glm::radians(theta),glm::vec3(0,1,0));

//        update_parent(&skeleton[ID],skeleton[ID].world_mat);
    }

    void apply_weights(){
        for(int j = 0; j< this->mesh.vertices.size() ; j++){
            float distance = 0.0;
            Vertex vertex = mesh.vertices[j];
//            std::cout << vertex.Position[0] << vertex.Position[1] << vertex.Position[2] << std::endl;
            for(Bone bone : skeleton){
//                std::cout << glm::distance(bone.pos,vertex.Position) << std::endl;
                distance += glm::distance(bone.pos,vertex.Position);
            }
            for(int i = 0 ; i < skeleton.size() ; i++){
                vertex.weights.push_back(1-glm::distance(vertex.Position,skeleton[i].pos)/distance);
//                1-glm::distance(vertex.Position,skeleton[i].pos)/distance
//                std::cout << 1-glm::distance(vertex.Position,skeleton[i].pos)/distance << std::endl;
            }
//            std::cout << vertex.weights[0] << std::endl;
            mesh.vertices[j] = vertex;
        }
    }


};


#endif //OPENGLRENDU_SKIN_H
