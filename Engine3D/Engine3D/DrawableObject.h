#pragma once
#include "BitmapHandler.h"
#include "GameObject.h"

/**
 * @brief Klasa abstrakcyjna reprezentuj�ca obiekt rysowalny
 *
 * Klasa `DrawableObject` dziedziczy po `GameObject` i definiuje interfejs dla obiekt�w, kt�re mog� by� renderowane
 */
class DrawableObject :
    public GameObject
{
protected:
    BitmapHandler textureHandler; ///< Obiekt obs�uguj�cy tekstury
    GLuint textureID; ///< Identyfikator tekstury OpenGL
public:
    /**
     * @brief Konstruktor domy�lny
     *
     * Inicjuje now� instancj� klasy `DrawableObject`
     */
    DrawableObject();

    /**
     * @brief Destruktor wirtualny
     *
     * Usuwa instancje klasy `DrawableObject`, w tym zwalniaj�c zasoby
     */
    virtual ~DrawableObject();

    /**
     * @brief Wirtualna metoda rysuj�ca figur�
     *
     * Metoda abstrakcyjna, kt�ra musi by� zaimplementowana przez klasy pochodne
     * Rysuje figur� w przestrzeni graficznej
     */
    virtual void draw() = 0;

    /**
     * @brief �aduje tekstur� z pliku
     *
     * �aduje tekstur� z podanego pliku i zwraca warto�� logiczn� informuj�c� o sukcesie operacji
     *
     * @param[in] filePath �cie�ka do pliku z tekstur�
     * @return `true`, je�li tekstura zosta�a za�adowana pomy�lnie, `false` w przeciwnym razie
     */
    bool loadTexture(const char* filePath) {
        return textureHandler.LoadTexture(filePath);
    }

    /**
     * @brief Pobiera identyfikator tekstury
     *
     * Zwraca identyfikator OpenGL aktualnie za�adowanej tekstury
     *
     * @return Identyfikator tekstury OpenGL (`GLuint`)
     */
    GLuint getTextureID() const { return textureHandler.GetTextureID(); }

};

