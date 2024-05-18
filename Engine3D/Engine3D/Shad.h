#pragma once
#include <GL/freeglut.h>
#include <vector>

class Shad{
private:
    // Ustawienia œwiat³a
    float lightPos[4]{ 0.0f, 0.0f, 1.0f, 0.0f };        // Pozycja œwiat³a
    float lightAmbient[4]{ 0.2f, 0.2f, 0.2f, 1.0f };    // Œwiat³o otoczenia
    float lightDiffuse[4]{ 0.8f, 0.8f, 0.8f, 1.0f };    // Œwiat³o rozproszone
    float lightSpecular[4]{ 1.0f, 1.0f, 1.0f, 1.0f };   // Œwiat³o odbite

    // Ustawienia materia³u 
    float matAmbient[4]{ 1.0f, 0.5f, 0.31f, 1.0f }; // Materia³ otoczenia
    float matDiffuse[4]{ 1.0f, 0.5f, 0.31f, 1.0f }; // Materia³ rozproszenia
    float matSpecular[4]{ 0.5f, 0.5f, 0.5f, 1.0f }; // Materia³ odbicia
    float matShininess[1] { 40.0f };                // Po³ysk materia³u

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

