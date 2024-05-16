#include "Engine.h"

//Inicjalizacje
GLfloat Engine::clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
Engine::ProjectionType Engine::projectionType = Engine::ProjectionType::ORTHOGRAPHIC;
Engine* Engine::engineInstance = nullptr;

Engine& Engine::getInstance(int argc, char** argv) {

    static Engine instance(argc, argv); // Tworzenie nowej instancji tylko jeœli nie istnieje jeszcze ¿adna

    return instance;
}


void Engine::setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    clearColor[0] = r;
    clearColor[1] = g;
    clearColor[2] = b;
    clearColor[3] = a;
}


void Engine::display() {
     
     glClearColor(getRed(), getGreen(), getBlue(), getAlpha()); // Ustawienie koloru t³a
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
     glColor3f(1.0f, 0.0f, 0.0f);
     glLoadIdentity();
     PrimitiveRenderer::drawRectangle(-2.0, -2.0, 2.0, 2.0);
     glColor3f(0.0f, 1.0f, 0.0f);
     PrimitiveRenderer::drawCircle(2.0, 2.0, 4.0, 50);
     glutSwapBuffers();
   
}

void Engine::reshape(int w, int h) {
    glViewport(0, 0, w, h);
    if (getProjectionType() == Engine::ProjectionType::PERSPECTIVE) {
        std::cout << "wybrano perspective" << std::endl;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (double)w / (double)h, -2.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
    }
    else {
        std::cout << "wybrano orto" << std::endl;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
    }

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluOrtho2D(-10, 10, -10, 10);
    //glMatrixMode(GL_MODELVIEW);


}


void Engine::keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // Escape key
        exit(0);
        break;
    default:
        break;
    }
}

void Engine::mouse(int button, int state, int x, int y) {
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
         std::cout << "Wcisnieto lewy przyycisk" << std::endl;
 }

void Engine::timer(int value) {

    if (engineInstance) {
            glutPostRedisplay();
            glutTimerFunc(1000 / engineInstance->getFPS(), timer, 0);
            std::cout << engineInstance->getFPS() <<" FPS" << std::endl;
        }
}

int Engine::getDisplayMode() {
     int displayMode = GLUT_RGB;

     if (doubleBuffering)
         displayMode |= GLUT_DOUBLE;
     if (useDepthBuffer)
         displayMode |= GLUT_DEPTH;
     return displayMode;
    }

void Engine::createWindow(const char* title) {
    if (fullscreen) {
        glutGameModeString("1920x1080:32");
        glutEnterGameMode();
    }
    else {
        glutInitDisplayMode(getDisplayMode());
        glutInitWindowSize(width, height);
        glutInitWindowPosition(100, 100);
        windowId = glutCreateWindow(title);
    }

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    if (useMouse)
        glutMouseFunc(mouse);
    if (useKeyboard)
        glutKeyboardFunc(keyboard);

    glutTimerFunc(0, timer, 0); // Uruchamiamy czasomierz


}

void Engine::close() {
    // Zamkniêcie okna i wyjœcie z trybu pe³noekranowego, jeœli jest w³¹czony
    glutLeaveGameMode();

    // Usuniêcie okna, jeœli zosta³o utworzone
    if (windowId != -1) {
        glutDestroyWindow(windowId);
        windowId = -1;
    }

    // Zakoñczenie biblioteki GLUT
    glutExit();
}



int main(int argc, char** argv) {
    //Obiekt engine
    Engine& engine = Engine::getInstance(argc, argv);
    //Wskaznik do niego
    Engine::engineInstance = &Engine::getInstance(argc, argv);
    engine.setFullscreen(false);
    engine.setWindowSize(1024, 768);
    engine.setFPS(30);
    engine.setMouseEnabled(true);
    engine.setKeyboardEnabled(true);
    engine.setDoubleBuffering(true);
    engine.setDepthBuffer(false);
    engine.setClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    engine.createWindow("OpenGL Engine");

    engine.run();
    engine.close();

    return 0;

}
