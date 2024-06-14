#pragma once
#include <GL/glew.h>
#include <string>

/**
 * @brief Klasa do obs³ugi bitmap i tekstur
 *
 * Klasa `BitmapHandler` umo¿liwia ³adowanie tekstur z plików i zarz¹dzanie ich identyfikatorami
 */
class BitmapHandler {
public:
    /**
     * @brief Konstruktor domyœlny
     *
     * Inicjuje now¹ instancjê klasy `BitmapHandler` i ustawia domyœlne wartoœci dla jej cz³onków
     */
    BitmapHandler();

    /**
     * @brief Destruktor
     *
     * Zwolnia zasoby alokowane przez instancjê klasy `BitmapHandler`, w tym tekstury OpenGL
     */
    ~BitmapHandler();

    /**
     * @brief £aduje teksturê z pliku
     *
     * Próbuje za³adowaæ teksturê z pliku o podanej nazwie i ustawia identyfikator tekstury
     *
     * @param[in] fileName Nazwa pliku z tekstur¹ do za³adowania
     * @return `true` jeœli tekstura zosta³a za³adowana pomyœlnie, `false` w przeciwnym razie
     */
    bool LoadTexture(const std::string& fileName);

    /**
     * @brief Pobiera identyfikator tekstury
     *
     * Zwraca identyfikator tekstury OpenGL, która zosta³a za³adowana przez tê instancjê klasy
     *
     * @return Identyfikator tekstury (`GLuint`)
     */
    GLuint GetTextureID() const;

private:
    GLuint textureID; ///< Identyfikator tekstury OpenGL

    /**
     * @brief Zwalnia zasoby tekstury
     *
     * Zwalnia zasoby zwi¹zane z tekstur¹, jeœli jest za³adowana
     */
    void FreeTexture();
};
