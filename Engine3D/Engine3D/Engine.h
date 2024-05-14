#pragma comment(lib, "freeglut.lib")
#include <GL/freeglut.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <glm.hpp>
#include <vec4.hpp>
#include <ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <ext/matrix_clip_space.hpp> // glm::perspective
#include <ext/scalar_constants.hpp>



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

    static void display();

    static void reshape(int w, int h);

    static void keyboard(unsigned char key, int x, int y);

    static void mouse(int button, int state, int x, int y) {
        // Obs³uga myszy
    }

    static void timer(int value);

    void update() {
        // Aktualizacja logiki gry
    }

    //Metoda sluzaca do okreslenia trybu wyswietlania
    int getDisplayMode();

public:
    Engine(int argc, char** argv) {
        glutInit(&argc, argv);
        windowId = -1; // Ustawienie domyœlnej wartoœci identyfikatora okna
    }

    void setFullscreen(bool fullscreen) {
        this->fullscreen = fullscreen;
    }

    void setWindowSize(int width, int height) {
        this->width = width;
        this->height = height;
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



};

