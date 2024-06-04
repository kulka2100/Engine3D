#pragma once
#include <glm.hpp>
#include <GL/freeglut.h>
class GameObject
{
protected:
    glm::mat4 modelMatrix;
public:
    /**
      * @brief konstruktor domyslny
      */
    GameObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~GameObject();

};

