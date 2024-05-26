#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

class Triangle : public ShapeObject {
private:
    float x1, x2, y1, y2, x3, y3;
    float r, g, b;

public:

    Triangle(float x1, float y1, float x2, float y2, float x3, float y3) : x1(x1), y1(y1), x2(x2), y2(y2), y3(y3), x3(x3){

    }

    float getX1() {
        return x1;
    }

    float getX2() {
        return x2;
    }

    float getY1() {
        return y1;
    }

    float getY2() {
        return y2;
    }

    float getX3() {
        return x3;
    }

    float getY3() {
        return y3;
    }

    void drawTriangle();

    void setColor(float r, float g, float b);
};

