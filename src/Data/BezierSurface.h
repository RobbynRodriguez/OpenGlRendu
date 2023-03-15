//
// Created by robbyn on 05/04/2022.
//

#ifndef OPENGLRENDU_BEZIERSURFACE_H
#define OPENGLRENDU_BEZIERSURFACE_H

#include <glad/glad.h>

#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "BezierCurve.h"

using namespace std;

#define MAX_BONE_INFLUENCE 4


using namespace glm;

class BezierSurface {
    // mesh Data
    vector<Vertex>       vertices;
    vector<unsigned int> indices;
    vector<vec3>      textures;
    unsigned int VAO;
    BezierCurve C1,C2;


public:
// constructor
    BezierSurface( BezierCurve c1,
                  BezierCurve c2)
            : C1(c1), C2(c2) {
//        this->textures = textures;

//        init_ctrl_pts();

        init_mesh();
        CalculateNormals();

        // now that we have all the required data, set the vertex buffers and its attribute pointers.
        setupMesh();
    }


    int draw() {
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, vertices.size()*6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        return 1;
    }





private:

    // render data
    unsigned int VBO, EBO;

    vector<vector<glm::vec3>> controlPoints;
    vector<glm::vec3> cctrl;


    glm::vec3 lerp(float t,vector<glm::vec3> pts_ctrl)
    {
        vector<glm::vec3> ordre = pts_ctrl;
        int nb_pts_ctrl = ordre.size();
        for(int i = 1 ; i < nb_pts_ctrl ; i++){
            for(int j = 0 ; j < nb_pts_ctrl-i ; j++) {
                ordre[j] = ((1-t) * ordre[j]) + (ordre[j+1] * t);
            }
        }
//        std::cout << "point : " << ordre[0][0] << std::endl;
        return(ordre[0]);
    }

    void CalculateNormals()
    {
        size_t vertexCount = vertices.size()*6;
        vec3 normal2;
        glm::vec3 normal;

        for( int i = 0; i < vertices.size(); ++i )
        {
            vertices[i].Normal = {0.0,0.0,0.0};
        }
        for( int i = 0; i < indices.size(); i += 3 )
        {

            // get the three vertices that make the faces
            glm::vec3 p0 = vertices[indices[i]].Position;
            glm::vec3 p1 = vertices[indices[i+1]].Position;
            glm::vec3 p2 = vertices[indices[i+2]].Position;

            glm::vec3 e1 = p1 - p0;
            glm::vec3 e2 = p2 - p0;
            normal = glm::cross( e1, e2 );
//            normal2 = glm::normalize(normal);
//            cout << "e1 : "<< e1[0] << e1[1] << e2[2] << endl;
//            cout << "e2 : "<< e2[0] << e2[1] << e2[2] << endl;
//            cout << "normal : "<< normal[0] << normal[1]<< normal[2] << endl;
//            cout << "normal nrom: "<< normal2[0] << normal2[1]<< normal2[2] << endl;
            // Store the face's normal for each of the vertices that make up the face.
            vertices[indices[i]].Normal += normal ;
            vertices[indices[i+1]].Normal  += normal ;
            vertices[indices[i+2]].Normal  += normal;
        }


        // Now loop through each vertex vector, and avarage out all the normals stored.
        for( int i = 0; i < vertices.size(); ++i )
        {
            vertices[i].Normal = glm::normalize(vertices[i].Normal);
        }
    }




    void init_mesh() {
        vector<glm::vec3> pts_c1,pts_c2;
//        pts_c1 = C1.vertices;
//        pts_c2 = C2.vertices;
        Vertex point();

//        for(float i = 0 ; i< C1.vertices.size(); i ++)
//            for(float j = 0 ; j< C2.vertices.size(); j ++) {
//                point.Position = vec4(C1.vertices[i] * C2.vertices[j],0);
//                point.TexCoords = {i/C1.vertices.size(),j/C2.vertices.size()};
//                vertices.push_back(point);
//            }

        int n,m;
        n = C1.vertices.size();
        m = C2.vertices.size();
        for(int i = 0; i<n-1;i++){
            for(int j = 0; j<m-1;j++){
                //1er triangle
                indices.push_back(i*m+j);
                indices.push_back(i*m+j+1);
                indices.push_back((i+1)*m+j+1);
                //2nd triangle
                indices.push_back(i*m+j);
                indices.push_back((i+1)*m+j);
                indices.push_back((i+1)*m+j+1);
            }
        }

    }


    // initializes all the buffer objects/arrays
    void setupMesh()
    {
        // create buffers/arrays
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        // load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        // set the vertex attribute pointers
        // vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
        // vertex texture coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
        // vertex tangent
        glBindVertexArray(0);
    }

};


#endif //OPENGLRENDU_BEZIERSURFACE_H
