//
// Created by robbyn on 06/04/2022.
//

#ifndef OPENGLRENDU_LIGHTS_H
#define OPENGLRENDU_LIGHTS_H

#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <tuple>
#include <math.h>
#include <vector>

#include <iostream>
#include "Shader.h"

#define DIR 1
#define SPOT 2
#define POINT 0

using namespace std;
using namespace glm;


struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec4 color;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;
    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

class Lights {
public:
    vector<PointLight> points;

    Lights(vector<PointLight> &points) : points(points) {}

    Lights() {}

    void addpointlight(PointLight point){ points.push_back(point); }


    void updateShader(Shader shader){
        //dirLight
//        shader.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//        shader.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
//        shader.setVec3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
//        shader.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);

        //pointLights
        for(int i = 0 ; i< points.size(); i++){
            string name = "light[" + to_string(i)+"]";
//            std::cout << name << endl;
            shader.setVec3(name+".position", points[i].position);
            shader.setVec3(name+".ambient", 0.05f, 0.05f, 0.05f);
            shader.setVec3(name+".diffuse", 0.8f, 0.8f, 0.8f);
            shader.setVec3(name+".specular", 1.0f, 1.0f, 1.0f);
            shader.setFloat(name+".constant", 1.0f);
            shader.setFloat(name+".linear", 0.027f);
            shader.setFloat(name+".quadratic", 0.0028f);
            shader.setVec4(name+".color", 1.0f,1.0f,1.0f,1.0f);
        }


    }



};


#endif //OPENGLRENDU_LIGHTS_H
