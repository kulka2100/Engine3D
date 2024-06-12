#pragma once
#include "BitmapHandler.h"
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

    
    void generateVertices();



public:
    Sphere(float radius, unsigned int rings, unsigned int sectors)
        : radius(radius), rings(rings), sectors(sectors) {
        generateVertices();
    }


    void draw() override;


    void setColor(float red, float green, float blue);
    
};

