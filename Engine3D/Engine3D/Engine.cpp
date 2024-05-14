#include "Engine.h"



 void Engine::display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

void Engine::reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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


void Engine::timer(int value) {
    Engine* engine = static_cast<Engine*>(glutGetWindowData());
    if (engine) {
        glutPostRedisplay();
        glutTimerFunc(1000 / engine->getFPS(), timer, 0);
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

    running = true;
    glutTimerFunc(1000 / fps, timer, 0); // Uruchamiamy czasomierz

    while (running) {
        glutMainLoopEvent(); // G³ówna pêtla GLUT
    }
}



int main(int argc, char** argv) {
    Engine engine(argc, argv);
    engine.setFullscreen(false);
    engine.setWindowSize(1024, 768);
    engine.setFPS(30);
    engine.setMouseEnabled(true);
    engine.setKeyboardEnabled(true);
    engine.setDoubleBuffering(true);
    engine.setDepthBuffer(true);
    engine.createWindow("OpenGL Engine");
    return 0;

}
