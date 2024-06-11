#pragma once
#include <GL/freeglut.h>
#include <ext/matrix_transform.hpp>
#include <vector>
#include <gtc/type_ptr.hpp>

class Shad {
private:
    // Ustawienia œwiat³a 
    glm::vec4 lightPos{100.0f, 200.0f, 0.0f, 1.0f};
    glm::vec4 lightAmbient{ 0.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 lightDiffuse{ 0.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 lightSpecular{ 0.0f, 0.0f, 0.0f, 1.0f };


    // Ustawienia materia³u 
    glm::vec4 matDiffuse {1.0, 1.0, 1.0, 1.0};
    glm::vec4 matAmbient {1.0, 1.0, 1.0, 1.0};
    glm::vec4 matSpecular {1.0, 1.0, 1.0, 1.0};
    bool traceColor;

public:

    Shad() : traceColor(true) {
    }

    void init();

    void setLightPos(glm::vec4 pos);

    void setLightAmbient(glm::vec4 ambientLight);

    void setLightDiffuse(glm::vec4 diffuse);

    void setLightSpecular(glm::vec4 specular);

    void setMatDiffuse(glm::vec4 matDiffuse);

    //Metoda wlazcajaca sledzenie kolorow obiektow 
    void setTraceColor(bool trace);

    void setMatAmbient(glm::vec4 matAmbient);

    void setMatSpecular(glm::vec4 specular);

};


