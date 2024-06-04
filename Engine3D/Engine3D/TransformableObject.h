#pragma once
#include "GameObject.h"
#include <iostream>
#include <gtc/matrix_transform.hpp> 
#include <glm.hpp>
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

/**
 * @brief klasa reprezentujaca transormowalny obiekt ksztaltu, dziedziczaca po GameObject
 */
class TransformableObject :
    public GameObject
{
protected:
    glm::mat4 modelMatrix;
public:
    /**
      * @brief konstruktor domyslny
      */
    TransformableObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~TransformableObject();

    void setPosition(float x, float y, float z);

    void scale(float sx, float sy, float sz);

    void rotate(float angle, float rx, float ry, float rz);

    void translate(float tx, float ty, float tz);


};
