#include "Engine.h"


//Inicjalizacje
GLfloat Engine::clearColor[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
Engine::ProjectionType Engine::projectionType = Engine::ProjectionType::PERSPECTIVE;
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
     glLoadIdentity();

     glm::mat4 view = engineInstance->camera.getViewMatrix();
     glLoadMatrixf(glm::value_ptr(view));

     Cube cube(2.0);
     cube.setPosition(0.0, 0.0, -5.0);
     cube.setRotate(45.0, 1.0, 1.0, 0.0);

     cube.setColor(0, 0.0, 0.0, 0.0);
     cube.setColor(1, 0.0, 0.0, 0.0);
     cube.setColor(2, 0.0, 0.0, 0.0);
     cube.setColor(3, 1.0, 0.0, 0.0);
     cube.setColor(4, 1.0, 0.0, 0.0);
     cube.setColor(5, 1.0, 0.0, 0.0);
     cube.setColor(6, 1.0, 0.0, 0.0);
     cube.setColor(7, 1.0, 0.0, 0.0);
     cube.setColor(8, 1.0, 0.0, 0.0);

    //// cube.setFullColor(0.0, 1.0, 1.0);
     cube.draw();

     glutSwapBuffers();
   
}

void Engine::reshape(int w, int h) {
    glViewport(0, 0, w, h);
    if (getProjectionType() == Engine::ProjectionType::PERSPECTIVE) {
        std::cout << "wybrano perspective" << std::endl;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, (double)w / (double)h, 1.0, 100.0);
        glMatrixMode(GL_MODELVIEW);
    }
    else {
        std::cout << "wybrano orto" << std::endl;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
        glMatrixMode(GL_MODELVIEW);
    }
}


void Engine::keyboard(unsigned char key, int x, int y) {
    float cameraSpeed = 0.5f;
    switch (key) {
    case 27: // Escape key
        exit(0);
        break;
    case 'w':
        engineInstance->camera.move(engineInstance->camera.getFront() * cameraSpeed);
        break;
    case 's':
        engineInstance->camera.move(-engineInstance->camera.getFront() * cameraSpeed);
        break;
    case 'a':
        engineInstance->camera.move(-engineInstance->camera.getRight() * cameraSpeed);
        break;
    case 'd':
        engineInstance->camera.move(engineInstance->camera.getRight() * cameraSpeed);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void Engine::specialKeys(int key, int x, int y) {
    float rotationSpeed = 1.0f;
    switch (key) {
    case GLUT_KEY_UP:
        engineInstance->camera.rotate(rotationSpeed, 0);
        break;
    case GLUT_KEY_DOWN:
        engineInstance->camera.rotate(-rotationSpeed, 0);
        break;
    case GLUT_KEY_LEFT:
        engineInstance->camera.rotate(0, -rotationSpeed);
        break;
    case GLUT_KEY_RIGHT:
        engineInstance->camera.rotate(0, rotationSpeed);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void Engine::mouse(int button, int state, int x, int y) {
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
         std::cout << "Wcisnieto lewy przyycisk" << std::endl;
 }

void Engine::timer(int value) {

    if (engineInstance) {
            glutPostRedisplay();
            glutTimerFunc(1000 / engineInstance->getFPS(), timer, 0);
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

    Shad shad;
    shad.setLightPos(1.0f, 0.0f, 0.0f, 1.0f);
    shad.setLightAmbient(1.0f, 1.0f, 1.0f, 1.0f);
    shad.setMatShininess(0.0);
    shad.init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    if (useMouse)
        glutMouseFunc(mouse);
    if (useKeyboard) {
        glutKeyboardFunc(keyboard);
        glutSpecialFunc(specialKeys);
    }

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
    engine.setFPS(60);
    engine.setMouseEnabled(true);
    engine.setKeyboardEnabled(true);
    engine.setDoubleBuffering(true);
    engine.setDepthBuffer(true);
    engine.setClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    engine.createWindow("OpenGL Engine");

    engine.run();
    engine.close();

    return 0;

}
