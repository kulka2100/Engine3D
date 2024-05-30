#pragma once
#include "GameObject.h"
#include <iostream>

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


    void getInfo() {
        std::cout << "Im transfromable class" << std::endl;
    }
    /**
     * @brief destruktor wirtualny
     */
    virtual ~TransformableObject();

};
