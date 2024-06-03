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

    /**
     * @brief wirtualna metoda rysujaca figury
     */
    virtual void draw() = 0;

};

