#pragma once
#include "GameObject.h"
#include <iostream>
#include <gtc/matrix_transform.hpp> 
#include <glm.hpp>

/**
 * @brief klasa reprezentujaca transormowalny obiekt ksztaltu, dziedziczaca po GameObject
 */
class TransformableObject :
    public GameObject
{
public:
    /**
      * @brief konstruktor domyslny
      */
    TransformableObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~TransformableObject();
};
