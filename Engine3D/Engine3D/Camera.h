#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

/**
 * @brief Klasa reprezentuj�ca kamer� 3D
 *
 * Klasa `Camera` umo�liwia manipulacj� pozycj� i orientacj� kamery oraz obliczanie macierzy widoku
 */
class Camera
{
public:
    /**
     * @brief Konstruktor domy�lny
     *
     * Inicjuje now� instancj� klasy `Camera` z domy�lnymi warto�ciami pozycji i orientacji
     */
    Camera();

    /**
     * @brief Ustawia pozycj� kamery
     *
     * Ustawia pozycj� kamery w przestrzeni 3D
     *
     * @param[in] position Nowa pozycja kamery
     */
    void setPosition(const glm::vec3& position);

    /**
     * @brief Ustawia rotacj� kamery
     *
     * Ustawia k�ty nachylenia (pitch) i obrotu (yaw) kamery
     *
     * @param[in] pitch K�t nachylenia (w stopniach)
     * @param[in] yaw K�t obrotu (w stopniach)
     */
    void setRotation(float pitch, float yaw);

    /**
     * @brief Przesuwa kamer� o zadany wektor
     *
     * Przesuwa pozycj� kamery o okre�lony wektor przesuni�cia
     *
     * @param[in] offset Wektor przesuni�cia
     */
    void move(const glm::vec3& offset);

    /**
     * @brief Obraca kamer� o zadane k�ty
     *
     * Obraca kamer� o podane warto�ci k�t�w nachylenia (pitch) i obrotu (yaw)
     *
     * @param[in] pitchOffset Zmiana k�ta nachylenia (w stopniach)
     * @param[in] yawOffset Zmiana k�ta obrotu (w stopniach)
     */
    void rotate(float pitchOffset, float yawOffset);

    /**
     * @brief Pobiera macierz widoku kamery
     *
     * Oblicza i zwraca macierz widoku kamery na podstawie jej aktualnej pozycji i orientacji
     *
     * @return Macierz widoku (`glm::mat4`)
     */
    glm::mat4 getViewMatrix() const;

    /**
     * @brief Pobiera wektor przedni kamery
     *
     * Zwraca znormalizowany wektor przedni kamery
     *
     * @return Wektor przedni (`glm::vec3`)
     */
    glm::vec3 getFront() const;

    /**
     * @brief Pobiera wektor prawy kamery
     *
     * Zwraca znormalizowany wektor prawy kamery
     *
     * @return Wektor prawy (`glm::vec3`)
     */
    glm::vec3 getRight() const;

private:
    glm::vec3 position; ///< Aktualna pozycja kamery
    float pitch; ///< K�t nachylenia kamery (w stopniach)
    float yaw;   ///< K�t obrotu kamery (w stopniach)
    glm::vec3 front; ///< Znormalizowany wektor przedni kamery
    glm::vec3 up; ///< Znormalizowany wektor g�rny kamery
    glm::vec3 right; ///< Znormalizowany wektor prawy kamery

    /**
     * @brief Aktualizuje wektory kamery
     *
     * Przelicza wektory `front`, `up` i `right` na podstawie aktualnych warto�ci `pitch` i `yaw`
     */
    void updateCameraVectors();
};

