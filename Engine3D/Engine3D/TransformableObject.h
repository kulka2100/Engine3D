#pragma once
#include "GameObject.h"

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
