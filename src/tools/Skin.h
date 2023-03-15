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


    explicit Skin(const vector<Bone> &skeleton, Mesh mesh) : skeleton(skeleton), mesh(mesh) {}


    void Linear_skinning(){
        glm::mat4  transfo;
        vector<Vertex> vertices = this->mesh.vertices;

        for(int i = 0; i < this->mesh.vertices.size() ; i++){
            Vertex vertex = vertices[i];
            if(vertex.weights.size() != skeleton.size()){
                std::cout << "weights size != bones size!" << std::endl;
                std::cout << vertex.weights.size() << this->skeleton.size() << std::endl;
            }
            glm::mat4 transfo = glm::mat4();
            for(int j = 0 ; i< skeleton.size(); j++){
                transfo += vertex.weights[j] * skeleton[j].transform;
            }
            vertex.Position = transfo * vertex.Position;
        }
    }

    void rotation(float theta, int ID){
        skeleton[ID].transform = glm::rotate(skeleton[ID].transform, glm::radians(theta),glm::vec3(0,1,0));
    }

    void apply_weights(){
        for(Vertex vertex : this->mesh.vertices){
            std::cout << vertex.Position[0] << vertex.Position[1] << vertex.Position[2] << std::endl;
            vertex.weights;
            float distance = 0.0;
            for(Bone bone : skeleton){

                distance += glm::distance(bone.coord,vertex.Position);
            }
            for(int i = 0 ; i < skeleton.size() ; i++){
                vertex.weights.push_back(1-glm::distance(vertex.Position,skeleton[i].coord)/distance);
                std::cout << 1-glm::distance(vertex.Position,skeleton[i].coord)/distance << std::endl;
            }
        }
    }

};


#endif //OPENGLRENDU_SKIN_H
