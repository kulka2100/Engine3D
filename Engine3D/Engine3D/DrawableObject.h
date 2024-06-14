#pragma once
#include "BitmapHandler.h"
#include "GameObject.h"

/**
 * @brief Klasa abstrakcyjna reprezentuj¹ca obiekt rysowalny
 *
 * Klasa `DrawableObject` dziedziczy po `GameObject` i definiuje interfejs dla obiektów, które mog¹ byæ renderowane
 */
class DrawableObject :
    public GameObject
{
protected:
    BitmapHandler textureHandler; ///< Obiekt obs³uguj¹cy tekstury
    GLuint textureID; ///< Identyfikator tekstury OpenGL
public:
    /**
     * @brief Konstruktor domyœlny
     *
     * Inicjuje now¹ instancjê klasy `DrawableObject`
     */
    DrawableObject();

    /**
     * @brief Destruktor wirtualny
     *
     * Usuwa instancje klasy `DrawableObject`, w tym zwalniaj¹c zasoby
     */
    virtual ~DrawableObject();

    /**
     * @brief Wirtualna metoda rysuj¹ca figurê
     *
     * Metoda abstrakcyjna, która musi byæ zaimplementowana przez klasy pochodne
     * Rysuje figurê w przestrzeni graficznej
     */
    virtual void draw() = 0;

    /**
     * @brief £aduje teksturê z pliku
     *
     * £aduje teksturê z podanego pliku i zwraca wartoœæ logiczn¹ informuj¹c¹ o sukcesie operacji
     *
     * @param[in] filePath Œcie¿ka do pliku z tekstur¹
     * @return `true`, jeœli tekstura zosta³a za³adowana pomyœlnie, `false` w przeciwnym razie
     */
    bool loadTexture(const char* filePath) {
        return textureHandler.LoadTexture(filePath);
    }

    /**
     * @brief Pobiera identyfikator tekstury
     *
     * Zwraca identyfikator OpenGL aktualnie za³adowanej tekstury
     *
     * @return Identyfikator tekstury OpenGL (`GLuint`)
     */
    GLuint getTextureID() const { return textureHandler.GetTextureID(); }

};

