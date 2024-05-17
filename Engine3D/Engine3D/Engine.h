#pragma comment(lib, "freeglut.lib")
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include <ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <ext/matrix_clip_space.hpp> // glm::perspective
#include <ext/scalar_constants.hpp>
#include "Cube.h"
#include "Circle.h"
#include "Rectangl.h"
#include "Line.h"
#include "Triangle.h"


class Engine {

private:
    int  windowId;
    bool fullscreen;
    int  width;
    int  height;
    int  fps;
    bool useMouse;
    bool useKeyboard;
    bool doubleBuffering;
    bool useDepthBuffer;
    bool running;

    static GLfloat clearColor[4];
    enum ProjectionType{ PERSPECTIVE, ORTHOGRAPHIC }; // Typ wyliczeniowy do okreœlenia rodzaju rzutowania
    static ProjectionType projectionType; // Pole przechowuj¹ce aktualne rzutowanie


    static void display();

    static void reshape(int w, int h);

    static void keyboard(unsigned char key, int x, int y);

    static void mouse(int button, int state, int x, int y);

    static void timer(int value);


    void update() {
        // Aktualizacja logiki gry
    }

    //Metoda sluzaca do okreslenia trybu wyswietlania
    int getDisplayMode();
    

    Engine(int argc, char** argv) {
        glutInit(&argc, argv);
    }

public:

    //Wskaznika na obiekt silnika
    static Engine* engineInstance;
  
    static Engine& getInstance(int argc, char** argv);

    void setFullscreen(bool fullscreen) {
        this->fullscreen = fullscreen;
    }

    void setWindowSize(int width, int height) {
        this->width = width;
        this->height = height;
    }

    void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);


    static GLfloat getRed() {
        return clearColor[0];
    }

    static GLfloat getGreen() {
        return clearColor[1];
    }

    static GLfloat getBlue() {
        return clearColor[2];
    }

    static GLfloat getAlpha() {
        return clearColor[3];
    }


    void run() {
        glutMainLoop();
    }

    void setFPS(int fps) {
        this->fps = fps;
    }

    int getFPS() {
        return fps;
    }

    void setMouseEnabled(bool useMouse) {
        this->useMouse = useMouse;
    }

    void setKeyboardEnabled(bool useKeyboard) {
        this->useKeyboard = useKeyboard;
    }

    void setDoubleBuffering(bool doubleBuffering) {
        this->doubleBuffering = doubleBuffering;
    }

    void setDepthBuffer(bool useDepthBuffer) {
        this->useDepthBuffer = useDepthBuffer;
    }

    void createWindow(const char* title);

    void setProjectionType(ProjectionType type) {
        projectionType = type;
    }

    static ProjectionType getProjectionType() {
        return projectionType;
    }

   

    //Czyszczenie pamieci
    void close();

};

