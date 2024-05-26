#pragma once
#include "GameObject.h"
class UpdatableObject :
    public GameObject
{
public:
    /**
      * @brief konstruktor domyslny
      */
    UpdatableObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~UpdatableObject();
};

