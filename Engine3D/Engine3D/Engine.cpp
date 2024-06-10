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

void Engine::drawControlPanel() {
    // Ustawienie trybu rysowania na 2D
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Etykieta pierwszego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(5, height - 17);
    const unsigned char* label1 = (const unsigned char*)"Btn1";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label1);

    // Rysowanie pierwszego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 2);
    glVertex2i(28, height - 2);
    glVertex2i(28, height - 32);
    glVertex2i(2, height - 32);
    glEnd();

    // Etykieta drugiego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(5, height - 50);
    const unsigned char* label2 = (const unsigned char*)"Btn2";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label2);

    // Rysowanie drugiego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 34);
    glVertex2i(28, height - 34);
    glVertex2i(28, height - 64);
    glVertex2i(2, height - 64);
    glEnd();

    

    // Rysowanie panelu
    glColor3f(0.7f, 0.7f, 0.7f); // Jasnoszary kolor
    glBegin(GL_QUADS);
    glVertex2i(0, 600);
    glVertex2i(30, 600);
    glVertex2i(30, height);
    glVertex2i(0, height);
    glEnd();

    // Przywrócenie poprzedniego trybu rysowania
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void Engine::display() {
     
     glClearColor(getRed(), getGreen(), getBlue(), getAlpha()); // Ustawienie koloru t³a
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();

     glm::mat4 view = engineInstance->camera.getViewMatrix();
     glLoadMatrixf(glm::value_ptr(view));

     // Rysowanie panelu kontrolnego
     engineInstance->drawControlPanel();

     Pyramid pyramid(4.0f);
     pyramid.setPosition(0.0f, -1.0f, -6.0f);
     //pyramid.rotate(45.0, 50.0, 0.0, 1.0);
     pyramid.draw();


     Sphere sp(10.0, 60, 60);
     sp.setColor(1.0, 0.5, 1.0);
     sp.translate(0.0f, 0.0f, -50.0f);
     sp.draw();

     /*
     Cube cube(2.0);
     cube.setPosition(0.0f, 0.0f, -5.0f);
     cube.scale(1.0, 1.0, 1.0);
     cube.rotate(45.0, 1.0, 0.0, 1.0);
     cube.translate(1.0, 1.0, -3.0);
     cube.setFullColor(0.0, 1.0, 1.0);
     cube.draw();
     */

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
    shad.setMatSpecular(1.0f, 1.0f, 1.0f, 1.0f);
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
