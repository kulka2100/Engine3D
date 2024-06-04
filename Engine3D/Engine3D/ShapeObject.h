#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <iostream>

class ShapeObject :
    public DrawableObject, TransformableObject
{
protected:
    glm::mat4 modelMatrix;
public:
    /**
      * @brief konstruktor domyslny
      */
    ShapeObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~ShapeObject();

    void setPosition(float x, float y, float z);

    void scale(float sx, float sy, float sz);

    void rotate(float angle, float rx, float ry, float rz);

    void translate(float tx, float ty, float tz);
};