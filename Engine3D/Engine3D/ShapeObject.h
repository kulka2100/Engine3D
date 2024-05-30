#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <iostream>

class ShapeObject :
    public DrawableObject, TransformableObject
{
public:
    /**
      * @brief konstruktor domyslny
      */
    ShapeObject();

    void getMess() {
        std::cout << "Im ShapeObject class" << std::endl;
    }
    /**
     * @brief destruktor wirtualny
     */
    virtual ~ShapeObject();

};

