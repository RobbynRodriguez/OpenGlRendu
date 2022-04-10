//
// Created by robbyn on 02/04/2022.
//

#ifndef OPENGLRENDU_BEZIERCURVE_H
#define OPENGLRENDU_BEZIERCURVE_H


#include <tuple>
#include "Mesh.h"
#include <math.h>

class BezierCurve {
public:

    int nb_pts_ctrl;
    float nb_seg;
    float pas;
    unsigned int VAO_CTRL,VAO_VER,VBO,EBO;
    vector<glm::vec3> pts_ctrl;
    vector<glm::vec3> vertices;
    vector<unsigned int> indices,indices_ver;

    const vector<glm::vec3> &getVertices() const {
        return vertices;
    }

    BezierCurve(vector<glm::vec3> pts_ctrl, const int nb_pts_ctrl,const int nb_seg)
    : pts_ctrl(pts_ctrl) {
        this->nb_pts_ctrl = nb_pts_ctrl;
        this->nb_seg = (float) nb_seg;
        this->vertices.clear();
        this->pas = 1.0f/nb_seg;

        computeNVertexBesierCurve3D();

        for(int i =0; i<pts_ctrl.size();i++){
            indices.push_back(i);
        }
        for(int i =0; i<vertices.size();i++){
            indices_ver.push_back(i);
        }

        initialize();
    }

    int getNbPtsCtrl() const {
        return nb_pts_ctrl;
    }

    glm::vec3 lerp(float t)
    {
        vector<glm::vec3> ordre = pts_ctrl;
        for(int i = 1 ; i < nb_pts_ctrl ; i++){
            for(int j = 0 ; j < nb_pts_ctrl-i ; j++) {
                    ordre[j] = ((1-t) * ordre[j]) + (ordre[j+1] * t);
            }
        }
//        std::cout << "point : " << ordre[0][0] << std::endl;
        return(ordre[0]);
    }


    void computeNVertexBesierCurve3D()
    {
        for (float t = 0.0; t <= 1.0; t += pas) {
            vertices.push_back(lerp(t));
        }
    }


    void initialize() {


        glGenVertexArrays(1, &VAO_CTRL);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO_CTRL);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*pts_ctrl.size(), &pts_ctrl[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void *) 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
//        glBindVertexArray(0);

        glGenVertexArrays(1, &VAO_VER);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindVertexArray(VAO_VER);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3)*vertices.size(), &vertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_ver.size() * sizeof(unsigned int), &indices_ver[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), (void *) 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }



int draw() {
    glBindVertexArray(VAO_CTRL);
    glLineWidth(1);
    glPointSize(10);
    glDrawElements(GL_POINTS, static_cast<unsigned int>(pts_ctrl.size()), GL_UNSIGNED_INT, 0);
    glDrawElements(GL_LINE_STRIP, pts_ctrl.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindVertexArray(VAO_VER);
    glLineWidth(1);
    glDrawElements(GL_LINE_STRIP, vertices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

    return 1;
}



};


#endif //OPENGLRENDU_BEZIERCURVE_H
