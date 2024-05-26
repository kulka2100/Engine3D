#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
class ShapeObject :
    public DrawableObject, TransformableObject
{
public:
    /**
      * @brief konstruktor domyslny
      */
    ShapeObject();

    /**
     * @brief destruktor wirtualny
     */
    virtual ~ShapeObject();

};

