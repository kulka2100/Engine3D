#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp> 
#include <vector>
#include "ShapeObject.h"


class Pyramid : public ShapeObject {
private:
    float size;
	std::vector<float> vertices; // Tablica wierzchołków
	std::vector<float> normals;  // Tablica normalnych
	std::vector<float> colors;   // Tablica kolorów

   

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
    Pyramid(float size);

    void draw() override;

};

