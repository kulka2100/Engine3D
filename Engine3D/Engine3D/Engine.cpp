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


void drawButton(GLuint textureID, int x, int y, int width, int height) {
    // Rysuj teksturê przycisku na panelu kontrolnym
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2i(x, y);
    glTexCoord2f(1, 0); glVertex2i(x + width, y);
    glTexCoord2f(1, 1); glVertex2i(x + width, y + height);
    glTexCoord2f(0, 1); glVertex2i(x, y + height);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void Engine::drawControlPanel() {
    glDisable(GL_LIGHTING);
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
    glRasterPos2i(7, height - 21);
    const unsigned char* label1 = (const unsigned char*)"Kamera";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label1);

    // Rysowanie pierwszego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 2);
    glVertex2i(56, height - 2);
    glVertex2i(56, height - 32);
    glVertex2i(2, height - 32);
    glEnd();


    // Etykieta drugiego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(6, height - 53);
    const unsigned char* label2 = (const unsigned char*)"Przesun";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label2);

    // Rysowanie drugiego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 34);
    glVertex2i(56, height - 34);
    glVertex2i(56, height - 64);
    glVertex2i(2, height - 64);
    glEnd();

    // Etykieta trzeciego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(11, height - 85);
    const unsigned char* label3 = (const unsigned char*)"Obroc";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label3);

    // Rysowanie trzeciego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 66);
    glVertex2i(56, height - 66);
    glVertex2i(56, height - 96);
    glVertex2i(2, height - 96);
    glEnd();

    // Etykieta czwartego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(11, height - 117);
    const unsigned char* label4 = (const unsigned char*)"Skaluj";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label4);

    // Rysowanie czwartego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 98);
    glVertex2i(56, height - 98);
    glVertex2i(56, height - 128);
    glVertex2i(2, height - 128);
    glEnd();

    // Etykieta piatego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(9, height - 149);
    const unsigned char* label5 = (const unsigned char*)"Swiatlo";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label5);

    // Rysowanie piatego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 130);
    glVertex2i(56, height - 130);
    glVertex2i(56, height - 160);
    glVertex2i(2, height - 160);
    glEnd();

    // Etykieta szostego przycisku
    glColor3f(1.0f, 1.0f, 1.0f); // Bia³y kolor tekstu
    glRasterPos2i(14, height - 181);
    const unsigned char* label6 = (const unsigned char*)"Cien";
    glutBitmapString(GLUT_BITMAP_HELVETICA_12, label6);

    // Rysowanie szostego przycisku
    glColor3f(0.3f, 0.3f, 0.3f); // Ciemniejszy kolor przycisku
    glBegin(GL_QUADS);
    glVertex2i(2, height - 162);
    glVertex2i(56, height - 162);
    glVertex2i(56, height - 192);
    glVertex2i(2, height - 192);
    glEnd();

    
   
    // Rysowanie panelu
    glColor3f(0.7f, 0.7f, 0.7f); // Jasnoszary kolor
    glBegin(GL_QUADS);
    glVertex2i(0, 574);
    glVertex2i(58, 574);
    glVertex2i(58, height);
    glVertex2i(0, height);
    glEnd();

    glEnable(GL_LIGHTING);
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

     if (engineInstance->lightEnabled) {
         glEnable(GL_LIGHTING);
     }
     else {
         glDisable(GL_LIGHTING);
     }

     // Rysowanie panelu kontrolnego
     engineInstance->drawControlPanel();

     engineInstance->pyramid.draw();


     Sphere sp(10.0, 60, 60);

     sp.translate(0.0f, 0.0f, -30.0f);
     sp.draw();

     /*
     Cube cube(150.0f);
     cube.setPosition(0.0f, 0.0f, -5.0f);
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
        if (engineInstance->engineMode == 0)
            engineInstance->camera.move(engineInstance->camera.getFront() * cameraSpeed);
        else if (engineInstance->engineMode == 1) 
            engineInstance->pyramid.translate(0.0f, 0.0f, -1.0f);
        break;
    case 's':
        if (engineInstance->engineMode == 0)
            engineInstance->camera.move(-engineInstance->camera.getFront() * cameraSpeed);
        else if (engineInstance->engineMode == 1)
            engineInstance->pyramid.translate(0.0f, 0.0f, 1.0f);
        break;
    case 'a':
        if (engineInstance->engineMode == 0)
            engineInstance->camera.move(-engineInstance->camera.getRight() * cameraSpeed);
        else if (engineInstance->engineMode == 2)
            engineInstance->pyramid.rotate(10.0f, 0.0f, 1.0f, 0.0f);
        break;
    case 'd':
        if (engineInstance->engineMode == 0)
            engineInstance->camera.move(engineInstance->camera.getRight() * cameraSpeed);
        else if (engineInstance->engineMode == 2)
            engineInstance->pyramid.rotate(10.0f, 0.0f, -1.0f, 0.0f);
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
        if (engineInstance->engineMode == 0) 
            engineInstance->camera.rotate(rotationSpeed, 0);        
        else if (engineInstance->engineMode == 1)
            engineInstance->pyramid.translate(0.0f, 1.0f, 0.0f);
        else if (engineInstance->engineMode == 2)
            engineInstance->pyramid.rotate(10.0f, -1.0f, 0.0f, 0.0f);
        else if (engineInstance->engineMode == 3)
            engineInstance->pyramid.scale(1.1f, 1.1f, 1.1f);
        break;
    case GLUT_KEY_DOWN:
        if (engineInstance->engineMode == 0)
            engineInstance->camera.rotate(-rotationSpeed, 0);
        else if (engineInstance->engineMode == 1)
            engineInstance->pyramid.translate(0.0f, -1.0f, 0.0f);
        else if (engineInstance->engineMode == 2)
            engineInstance->pyramid.rotate(10.0f, 1.0f, 0.0f, 0.0f);
        else if (engineInstance->engineMode == 3)
            engineInstance->pyramid.scale(0.9f, 0.9f, 0.9f);
        break;
    case GLUT_KEY_LEFT:
        if (engineInstance->engineMode == 0)
            engineInstance->camera.rotate(0, -rotationSpeed);
        else if (engineInstance->engineMode == 1)
            engineInstance->pyramid.translate(-1.0f, 0.0f, 0.0f);
        else if (engineInstance->engineMode == 2)
            engineInstance->pyramid.rotate(10.0f, 0.0f, 0.0f, 1.0f);
        break;
    case GLUT_KEY_RIGHT:
        if (engineInstance->engineMode == 0)
            engineInstance->camera.rotate(0, rotationSpeed);
        else if (engineInstance->engineMode == 1)
            engineInstance->pyramid.translate(1.0f, 0.0f, 0.0f);
        else if (engineInstance->engineMode == 2)
            engineInstance->pyramid.rotate(10.0f, 0.0f, 0.0f, -1.0f);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void Engine::checkButtonClick(int x, int y) {  
    //Ustawienie na tryb kamery
    if (x >= 2 && x <= 56 && y >= 2 && y <= 32)
        engineInstance->engineMode = 0;
    // Ustawienie na przesuwanie obiektu
    else if (x >= 2 && x <= 56 && y >= 34 && y <= 64) {
        engineInstance->engineMode = 1;
    }
    // Ustawienie na obracanie obiektu
    else if (x >= 2 && x <= 56 && y >= 66 && y <= 96) {
        engineInstance->engineMode = 2;
    }
    // Ustawienie na skalowanie obiektu
    else if (x >= 2 && x <= 56 && y >= 98 && y <= 128) {
        engineInstance->engineMode = 3;
    }
    // Wlaczanie i wylaczanie swiatla
    else if (x >= 2 && x <= 56 && y >= 130 && y <= 160) {
        engineInstance->engineMode = 4;
    }
    // Wlaczanie i wylaczanie cieni
    else if (x >= 2 && x <= 56 && y >= 162 && y <= 192) {
        // Wlaczenie i wylaczenie cieni
    }
}

void Engine::mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        checkButtonClick(x, y);
        std::cout << engineInstance->engineMode;
        if (engineInstance->engineMode == 4) {
            std::cout << "wlaczam siwatlo";
            //Wlaczanie i wylaczanie swiatala 
            engineInstance->lightEnabled = !(engineInstance->lightEnabled);
            if (engineInstance->lightEnabled) {
                glEnable(GL_LIGHT0);
            }
            else {
                glDisable(GL_LIGHT0);
            }
            engineInstance->engineMode = 0;
          }

    }
     
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


    //Ustawianie parametrow oswietlenia
    Shad shad;
    shad.setTraceColor(false);
    shad.setLightAmbient(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));
    shad.setLightDiffuse(glm::vec4(1.0f, 0.1f, 0.1f, 1.0f));
    shad.setLightSpecular(glm::vec4(0.4f, 0.4f, 0.3f, 1.0f));

    shad.setMatDiffuse(glm::vec4(0.0, 0.0, 1.0, 1.0));
    shad.setMatAmbient(glm::vec4(1.0, 1.0, 1.0, 1.0));
    shad.setMatSpecular(glm::vec4(1.0, 1.0, 1.0, 1.0));

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
    //engine.setClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    engine.createWindow("OpenGL Engine");

    engine.run();
    engine.close();

    return 0;

}
