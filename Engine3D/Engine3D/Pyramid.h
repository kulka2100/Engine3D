#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp> 
#include <vector>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj�ca piramid� w przestrzeni 3D
 *
 * Klasa `Pyramid` dziedziczy po klasie `ShapeObject` i definiuje funkcjonalno��
 * obiektu piramidy, kt�ry mo�e by� rysowany w aplikacji graficznej
 */
class Pyramid : public ShapeObject {
private:
    float size; ///< Rozmiar piramidy

    std::vector<float> vertices; ///< Tablica wierzcho�k�w piramidy
    std::vector<float> normals;  ///< Tablica normalnych piramidy
    std::vector<float> colors;   ///< Tablica kolor�w piramidy

   

    GLubyte indices[18] = {
       0, 1, 2,            //Przednia sciana
       0, 2, 3,            //Prawa sicana
       0, 1, 4,            //Lewa sciana
       3, 0, 4,            //Tylna sciana
       1, 2, 4,            //Podstawa (2 trojkaty)
       2, 3, 4            
    }; ///< Indeksy wierzcho�k�w piramidy do rysowania

    /**
     * @brief Inicjuje tablic� wierzcho�k�w piramidy
     *
     * Metoda inicjuje tablic� wierzcho�k�w piramidy na podstawie jej rozmiaru
     * Ustawia r�wnie� odpowiednie normalne i kolory dla wierzcho�k�w
     */
    void initVertices();
    
public:
    /**
     * @brief Konstruktor inicjuj�cy piramid�
     *
     * Konstruktor inicjuje obiekt piramidy z podanym rozmiarem
     *
     * @param size Rozmiar piramidy
     */
    Pyramid(float size);

    /**
     * @brief Metoda rysuj�ca piramid�
     *
     * Metoda przedefiniowana z klasy bazowej `ShapeObject`
     * Rysuje piramid� na scenie
     */
    void draw() override;

};

