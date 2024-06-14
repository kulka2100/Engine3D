#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

/**
 * @brief Klasa reprezentuj¹ca kamerê 3D
 *
 * Klasa `Camera` umo¿liwia manipulacjê pozycj¹ i orientacj¹ kamery oraz obliczanie macierzy widoku
 */
class Camera
{
public:
    /**
     * @brief Konstruktor domyœlny
     *
     * Inicjuje now¹ instancjê klasy `Camera` z domyœlnymi wartoœciami pozycji i orientacji
     */
    Camera();

    /**
     * @brief Ustawia pozycjê kamery
     *
     * Ustawia pozycjê kamery w przestrzeni 3D
     *
     * @param[in] position Nowa pozycja kamery
     */
    void setPosition(const glm::vec3& position);

    /**
     * @brief Ustawia rotacjê kamery
     *
     * Ustawia k¹ty nachylenia (pitch) i obrotu (yaw) kamery
     *
     * @param[in] pitch K¹t nachylenia (w stopniach)
     * @param[in] yaw K¹t obrotu (w stopniach)
     */
    void setRotation(float pitch, float yaw);

    /**
     * @brief Przesuwa kamerê o zadany wektor
     *
     * Przesuwa pozycjê kamery o okreœlony wektor przesuniêcia
     *
     * @param[in] offset Wektor przesuniêcia
     */
    void move(const glm::vec3& offset);

    /**
     * @brief Obraca kamerê o zadane k¹ty
     *
     * Obraca kamerê o podane wartoœci k¹tów nachylenia (pitch) i obrotu (yaw)
     *
     * @param[in] pitchOffset Zmiana k¹ta nachylenia (w stopniach)
     * @param[in] yawOffset Zmiana k¹ta obrotu (w stopniach)
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
    float pitch; ///< K¹t nachylenia kamery (w stopniach)
    float yaw;   ///< K¹t obrotu kamery (w stopniach)
    glm::vec3 front; ///< Znormalizowany wektor przedni kamery
    glm::vec3 up; ///< Znormalizowany wektor górny kamery
    glm::vec3 right; ///< Znormalizowany wektor prawy kamery

    /**
     * @brief Aktualizuje wektory kamery
     *
     * Przelicza wektory `front`, `up` i `right` na podstawie aktualnych wartoœci `pitch` i `yaw`
     */
    void updateCameraVectors();
};

