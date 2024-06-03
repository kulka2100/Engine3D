#pragma once
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp> 
#include <vector>
#include "ShapeObject.h"


class Pyramid : public ShapeObject {
private:
    float size;
	std::vector<float> vertices; // Tablica wierzcho³ków
	std::vector<float> normals;  // Tablica normalnych
	std::vector<float> colors;   // Tablica kolorów
    //glm::mat4 modelMatrix;

   

    GLubyte indices[18] = {
       0, 1, 2,            //Przednia sciana
       0, 2, 3,            //Prawa sicana
       0, 1, 4,            //Lewa sciana
       3, 0, 4,            //Tylna sciana
       1, 2, 4,            //Podstawa (2 trojkaty)
       2, 3, 4            
    };

    void initVertices();
    
public:

	/*Pyramid(float size) : size(size), modelMatrix(glm::mat4(1.0f)) {
        initVertices();
	}*/
    Pyramid(float size) : size(size) {
        initVertices();
    }

    void draw() override;

    void scale(float sx, float sy, float sz);

    void rotate(float angle, float rx, float ry, float rz);


    void translate(float tx, float ty, float tz);

};

