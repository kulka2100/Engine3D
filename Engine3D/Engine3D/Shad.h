#pragma once
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <vector>
#include <gtc/type_ptr.hpp>

/**
 * @brief Klasa obs�uguj�ca ustawienia �wiat�a i materia�u dla sceny 3D
 *
 * Klasa `Shad` zarz�dza ustawieniami �r�d�a �wiat�a oraz w�a�ciwo�ciami materia�u
 * u�ywanymi do renderowania obiekt�w 3D
 */
class Shad {
private:
    // Ustawienia �wiat�a 
    glm::vec4 lightPos{ 30.0f, 30.0f, 0.0f, 1.0f };   ///< Pozycja �r�d�a �wiat�a
    glm::vec4 lightAmbient{ 0.2f, 0.2f, 0.2f, 1.0f }; ///< Sk�adowa ambient �wiat�a
    glm::vec4 lightDiffuse{ 0.8f, 0.8f, 0.8f, 1.0f }; ///< Sk�adowa diffuse �wiat�a
    glm::vec4 lightSpecular{ 1.0f, 1.0f, 1.0f, 1.0f }; ///< Sk�adowa specular �wiat�a


    // Ustawienia materia�u 
    glm::vec4 matDiffuse{ 1.0, 1.0, 1.0, 1.0 };   ///< Sk�adowa diffuse materia�u
    glm::vec4 matAmbient{ 1.0, 1.0, 1.0, 1.0 };   ///< Sk�adowa ambient materia�u
    glm::vec4 matSpecular{ 1.0, 1.0, 1.0, 1.0 };  ///< Sk�adowa specular materia�u
    int shininess; ///< Po�ysk materia�u
    bool traceColor; ///< Flaga okre�laj�ca, czy �ledzi� kolor obiekt�w

public:
    /**
     * @brief Konstruktor domy�lny inicjuj�cy �ledzenie kolor�w
     */
    Shad() : traceColor(true) {
    }

    /**
     * @brief Inicjuje ustawienia �wiat�a i materia�u
     *
     * Metoda inicjuje domy�lne ustawienia �r�d�a �wiat�a i materia�u
     */
    void init();

    /**
     * @brief Ustawia pozycj� �r�d�a �wiat�a
     *
     * @param pos Nowa pozycja �r�d�a �wiat�a
     */
    void setLightPos(glm::vec4 pos);

    /**
     * @brief Ustawia sk�adow� ambient �wiat�a
     *
     * @param ambientLight Nowa sk�adowa ambient �wiat�a
     */
    void setLightAmbient(glm::vec4 ambientLight);

    /**
     * @brief Ustawia sk�adow� diffuse �wiat�a
     *
     * @param diffuse Nowa sk�adowa diffuse �wiat�a
     */
    void setLightDiffuse(glm::vec4 diffuse);

    /**
     * @brief Ustawia sk�adow� specular �wiat�a
     *
     * @param specular Nowa sk�adowa specular �wiat�a
     */
    void setLightSpecular(glm::vec4 specular);

    /**
     * @brief Ustawia sk�adow� diffuse materia�u
     *
     * @param matDiffuse Nowa sk�adowa diffuse materia�u
     */
    void setMatDiffuse(glm::vec4 matDiffuse);

    /**
     * @brief Ustawia flag� okre�laj�c�, czy �ledzi� kolor obiekt�w
     *
     * @param trace Flaga true/false
     */
    void setTraceColor(bool trace);

    /**
     * @brief Ustawia sk�adow� ambient materia�u
     *
     * @param matAmbient Nowa sk�adowa ambient materia�u
     */
    void setMatAmbient(glm::vec4 matAmbient);

    /**
     * @brief Ustawia sk�adow� specular materia�u
     *
     * @param specular Nowa sk�adowa specular materia�u
     */
    void setMatSpecular(glm::vec4 specular);

    /**
     * @brief Ustawia po�ysk materia�u
     *
     * @param shininess Nowy po�ysk materia�u
     */
    void setMatShininess(int shininess);

};


