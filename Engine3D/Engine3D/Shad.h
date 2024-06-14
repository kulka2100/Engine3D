#pragma once
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <vector>
#include <gtc/type_ptr.hpp>

/**
 * @brief Klasa obs³uguj¹ca ustawienia œwiat³a i materia³u dla sceny 3D
 *
 * Klasa `Shad` zarz¹dza ustawieniami Ÿród³a œwiat³a oraz w³aœciwoœciami materia³u
 * u¿ywanymi do renderowania obiektów 3D
 */
class Shad {
private:
    // Ustawienia œwiat³a 
    glm::vec4 lightPos{ 30.0f, 30.0f, 0.0f, 1.0f };   ///< Pozycja Ÿród³a œwiat³a
    glm::vec4 lightAmbient{ 0.2f, 0.2f, 0.2f, 1.0f }; ///< Sk³adowa ambient œwiat³a
    glm::vec4 lightDiffuse{ 0.8f, 0.8f, 0.8f, 1.0f }; ///< Sk³adowa diffuse œwiat³a
    glm::vec4 lightSpecular{ 1.0f, 1.0f, 1.0f, 1.0f }; ///< Sk³adowa specular œwiat³a


    // Ustawienia materia³u 
    glm::vec4 matDiffuse{ 1.0, 1.0, 1.0, 1.0 };   ///< Sk³adowa diffuse materia³u
    glm::vec4 matAmbient{ 1.0, 1.0, 1.0, 1.0 };   ///< Sk³adowa ambient materia³u
    glm::vec4 matSpecular{ 1.0, 1.0, 1.0, 1.0 };  ///< Sk³adowa specular materia³u
    int shininess; ///< Po³ysk materia³u
    bool traceColor; ///< Flaga okreœlaj¹ca, czy œledziæ kolor obiektów

public:
    /**
     * @brief Konstruktor domyœlny inicjuj¹cy œledzenie kolorów
     */
    Shad() : traceColor(true) {
    }

    /**
     * @brief Inicjuje ustawienia œwiat³a i materia³u
     *
     * Metoda inicjuje domyœlne ustawienia Ÿród³a œwiat³a i materia³u
     */
    void init();

    /**
     * @brief Ustawia pozycjê Ÿród³a œwiat³a
     *
     * @param pos Nowa pozycja Ÿród³a œwiat³a
     */
    void setLightPos(glm::vec4 pos);

    /**
     * @brief Ustawia sk³adow¹ ambient œwiat³a
     *
     * @param ambientLight Nowa sk³adowa ambient œwiat³a
     */
    void setLightAmbient(glm::vec4 ambientLight);

    /**
     * @brief Ustawia sk³adow¹ diffuse œwiat³a
     *
     * @param diffuse Nowa sk³adowa diffuse œwiat³a
     */
    void setLightDiffuse(glm::vec4 diffuse);

    /**
     * @brief Ustawia sk³adow¹ specular œwiat³a
     *
     * @param specular Nowa sk³adowa specular œwiat³a
     */
    void setLightSpecular(glm::vec4 specular);

    /**
     * @brief Ustawia sk³adow¹ diffuse materia³u
     *
     * @param matDiffuse Nowa sk³adowa diffuse materia³u
     */
    void setMatDiffuse(glm::vec4 matDiffuse);

    /**
     * @brief Ustawia flagê okreœlaj¹c¹, czy œledziæ kolor obiektów
     *
     * @param trace Flaga true/false
     */
    void setTraceColor(bool trace);

    /**
     * @brief Ustawia sk³adow¹ ambient materia³u
     *
     * @param matAmbient Nowa sk³adowa ambient materia³u
     */
    void setMatAmbient(glm::vec4 matAmbient);

    /**
     * @brief Ustawia sk³adow¹ specular materia³u
     *
     * @param specular Nowa sk³adowa specular materia³u
     */
    void setMatSpecular(glm::vec4 specular);

    /**
     * @brief Ustawia po³ysk materia³u
     *
     * @param shininess Nowy po³ysk materia³u
     */
    void setMatShininess(int shininess);

};


