#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include "ShapeObject.h"

class Rectangl : public ShapeObject {
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

    void draw() override;

    void setColor(float r, float g, float b);

  
};

