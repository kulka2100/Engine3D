#pragma once
#include "BitmapHandler.h"
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp> 
#include <vector>
#include "ShapeObject.h"

/**
 * @brief Klasa reprezentuj¹ca piramidê w przestrzeni 3D
 *
 * Klasa `Pyramid` dziedziczy po klasie `ShapeObject` i definiuje funkcjonalnoœæ
 * obiektu piramidy, który mo¿e byæ rysowany w aplikacji graficznej
 */
class Pyramid : public ShapeObject {
private:
    float size; ///< Rozmiar piramidy

    std::vector<float> vertices; ///< Tablica wierzcho³ków piramidy
    std::vector<float> normals;  ///< Tablica normalnych piramidy
    std::vector<float> colors;   ///< Tablica kolorów piramidy

   

    GLubyte indices[18] = {
       0, 1, 2,            //Przednia sciana
       0, 2, 3,            //Prawa sicana
       0, 1, 4,            //Lewa sciana
       3, 0, 4,            //Tylna sciana
       1, 2, 4,            //Podstawa (2 trojkaty)
       2, 3, 4            
    }; ///< Indeksy wierzcho³ków piramidy do rysowania

    /**
     * @brief Inicjuje tablicê wierzcho³ków piramidy
     *
     * Metoda inicjuje tablicê wierzcho³ków piramidy na podstawie jej rozmiaru
     * Ustawia równie¿ odpowiednie normalne i kolory dla wierzcho³ków
     */
    void initVertices();
    
public:
    /**
     * @brief Konstruktor inicjuj¹cy piramidê
     *
     * Konstruktor inicjuje obiekt piramidy z podanym rozmiarem
     *
     * @param size Rozmiar piramidy
     */
    Pyramid(float size);

    /**
     * @brief Metoda rysuj¹ca piramidê
     *
     * Metoda przedefiniowana z klasy bazowej `ShapeObject`
     * Rysuje piramidê na scenie
     */
    void draw() override;

};

