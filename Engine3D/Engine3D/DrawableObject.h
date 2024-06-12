#pragma once
#include "BitmapHandler.h"
#include "GameObject.h"
class DrawableObject :
    public GameObject
{
protected:
    BitmapHandler textureHandler;
    GLuint textureID;
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

    bool loadTexture(const char* filePath) {
        return textureHandler.LoadTexture(filePath);
    }

    GLuint getTextureID() const { return textureHandler.GetTextureID(); }

};

