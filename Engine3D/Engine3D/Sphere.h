#pragma once
#include <GL/freeglut.h>
#include <vector>
#include <ext/matrix_transform.hpp> 
#include <corecrt_math_defines.h>
#include <glm.hpp>
#include "ShapeObject.h"


class Sphere : public ShapeObject {
private:
    float radius;
    unsigned int rings;
    unsigned int sectors;
    std::vector<GLfloat> vertices;
    std::vector<GLuint> indices;
    std::vector<GLfloat> colors;
    glm::mat4 modelMatrix;

    
    void generateVertices();



public:
    Sphere(float radius, unsigned int rings, unsigned int sectors)
        : radius(radius), rings(rings), sectors(sectors), modelMatrix(glm::mat4(1.0)) {
        generateVertices();
    }


    void draw() override;


    void setColor(float red, float green, float blue);

    
    
    void scale(float sx, float sy, float sz);

    void rotate(float angle, float rx, float ry, float rz);
    

    void translate(float tx, float ty, float tz);

    void setPosition(float x, float y, float z);
    
};

