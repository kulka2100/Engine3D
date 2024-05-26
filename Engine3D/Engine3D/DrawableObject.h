#pragma once
#include "GameObject.h"
class DrawableObject :
    public GameObject
{
public:
    /**
      * @brief konstruktor domyslny
      */
    DrawableObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~DrawableObject();

};

