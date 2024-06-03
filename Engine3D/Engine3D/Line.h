#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

class Line : public ShapeObject {
private:
    float x1;
    float y1;
    float x2;
    float y2;
    float r, g, b;

public:

    Line(float x1, float y1, float x2, float y2);

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

    void draw() override;

    void setColor(float r, float g, float b);

};