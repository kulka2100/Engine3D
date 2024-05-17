#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>

class Rectangl {
private:
    float x;
    float y;
    float width;
    float height;
    float r, g, b;


public:

    Rectangl(float x, float y, float width, float height);

    float getX() {
        return x;
    }

    float getY() {
        return y;
    }

    float getWidth() {
        return width;
    }

    float getHeight() {
        return height;
    }

    void drawRectangle();

    void setColor(float r, float g, float b);

  
};

