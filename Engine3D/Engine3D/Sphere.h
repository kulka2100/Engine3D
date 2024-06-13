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
    glm::vec3 colors = {0.5, 0.5, 0.0};
    bool solid;

public:
    Sphere(float radius, unsigned int rings, unsigned int sectors)
        : radius(radius), rings(rings), sectors(sectors), solid(false) {
    }


    void draw() override;

    //Metoda ustawiajaca typ Sfery (SOLID/ WIRED)
    void isSolid(bool solid);

    void setColor(float red, float green, float blue);
    
};

