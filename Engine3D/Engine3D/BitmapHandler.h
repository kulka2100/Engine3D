#pragma once
#include <GL/glew.h>
#include <string>

/**
 * @brief Klasa do obs�ugi bitmap i tekstur
 *
 * Klasa `BitmapHandler` umo�liwia �adowanie tekstur z plik�w i zarz�dzanie ich identyfikatorami
 */
class BitmapHandler {
public:
    /**
     * @brief Konstruktor domy�lny
     *
     * Inicjuje now� instancj� klasy `BitmapHandler` i ustawia domy�lne warto�ci dla jej cz�onk�w
     */
    BitmapHandler();

    /**
     * @brief Destruktor
     *
     * Zwolnia zasoby alokowane przez instancj� klasy `BitmapHandler`, w tym tekstury OpenGL
     */
    ~BitmapHandler();

    /**
     * @brief �aduje tekstur� z pliku
     *
     * Pr�buje za�adowa� tekstur� z pliku o podanej nazwie i ustawia identyfikator tekstury
     *
     * @param[in] fileName Nazwa pliku z tekstur� do za�adowania
     * @return `true` je�li tekstura zosta�a za�adowana pomy�lnie, `false` w przeciwnym razie
     */
    bool LoadTexture(const std::string& fileName);

    /**
     * @brief Pobiera identyfikator tekstury
     *
     * Zwraca identyfikator tekstury OpenGL, kt�ra zosta�a za�adowana przez t� instancj� klasy
     *
     * @return Identyfikator tekstury (`GLuint`)
     */
    GLuint GetTextureID() const;

private:
    GLuint textureID; ///< Identyfikator tekstury OpenGL

    /**
     * @brief Zwalnia zasoby tekstury
     *
     * Zwalnia zasoby zwi�zane z tekstur�, je�li jest za�adowana
     */
    void FreeTexture();
};
