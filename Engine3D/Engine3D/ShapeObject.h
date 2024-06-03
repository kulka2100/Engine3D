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



    void setPosition(float x, float y, float z) {
        modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
    }
};

