#pragma once
#include <GL/freeglut.h>
#include <vector>

class Shad{
private:
    // Ustawienia �wiat�a
    float lightPos[4]{ 0.0f, 0.0f, 1.0f, 0.0f };        // Pozycja �wiat�a
    float lightAmbient[4]{ 0.2f, 0.2f, 0.2f, 1.0f };    // �wiat�o otoczenia
    float lightDiffuse[4]{ 0.8f, 0.8f, 0.8f, 1.0f };    // �wiat�o rozproszone
    float lightSpecular[4]{ 1.0f, 1.0f, 1.0f, 1.0f };   // �wiat�o odbite

    // Ustawienia materia�u 
    float matAmbient[4]{ 1.0f, 0.5f, 0.31f, 1.0f }; // Materia� otoczenia
    float matDiffuse[4]{ 1.0f, 0.5f, 0.31f, 1.0f }; // Materia� rozproszenia
    float matSpecular[4]{ 0.5f, 0.5f, 0.5f, 1.0f }; // Materia� odbicia
    float matShininess[1] { 40.0f };                // Po�ysk materia�u

public:

    Shad() {
    }

    void init();

    void setLightPos(float x, float y, float z, float w);

    void setLightAmbient(float x, float y, float z, float w);

    void setLightDiffuse(float x, float y, float z, float w);

    void setLightSpecular(float x, float y, float z, float w);

    void setMatAmbient(float x, float y, float z, float w);

    void setMatDiffuse(float x, float y, float z, float w);

    void setMatSpecular(float x, float y, float z, float w);

    void setMatShininess(float x);
};

