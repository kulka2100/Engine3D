#pragma comment(lib, "freeglut.lib")
#include "BitmapHandler.h"
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <glm.hpp>
#include <vec4.hpp>
#include <ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <ext/matrix_clip_space.hpp> // glm::perspective
#include <ext/scalar_constants.hpp>
#include <gtc/matrix_transform.hpp>
#include "Cube.h"
#include "Sphere.h"
#include "Circle.h"
#include "Rectangl.h"
#include "Line.h"
#include "Triangle.h"
#include "Shad.h"
#include <GL/glut.h>
#include "Camera.h"
#include "Pyramid.h"


/**
 * @brief Klasa reprezentuj�ca silnik graficzny
 *
 * Klasa `Engine` zarz�dza g��wn� p�tl� programu oraz interakcj� z OpenGL
 */
class Engine {

private:
    int  windowId; ///< Identyfikator okna OpenGL
    bool fullscreen; ///< Flaga okre�laj�ca, czy aplikacja dzia�a w trybie pe�noekranowym
    int  width; ///< Szeroko�� okna
    int  height; ///< Wysoko�� okna
    int  fps; ///< Oczekiwana ilo�� klatek na sekund�
    bool useMouse; ///< Flaga okre�laj�ca, czy obs�uga myszy jest w��czona
    bool useKeyboard; ///< Flaga okre�laj�ca, czy obs�uga klawiatury jest w��czona
    bool doubleBuffering; ///< Flaga okre�laj�ca, czy u�ywane jest podw�jne buforowanie 
    bool useDepthBuffer; ///< Flaga okre�laj�ca, czy u�ywane jest buforowanie g��boko�ci
    bool running; ///< Flaga okre�laj�ca, czy silnik jest w trakcie dzia�ania
    Camera camera; ///< Obiekt kamery
    Pyramid pyramid; ///< Obiekt piramidy
    int engineMode; ///< Tryb pracy silnika
    bool lightEnabled; ///< Flaga okre�laj�ca, czy o�wietlenie jest w��czone
    bool flatShading; ///< Flaga okre�laj�ca, czy u�ywane jest p�askie cieniowanie
    BitmapHandler textureHandler; ///< Obiekt do obs�ugi tekstur
    GLuint textureID; ///< Identyfikator tekstury OpenGL
      

    static GLfloat clearColor[4]; ///< Kolor czyszczenia t�a (RGBA)
    enum ProjectionType { PERSPECTIVE, ORTHOGRAPHIC }; ///< Typ wyliczeniowy do okre�lenia rodzaju rzutowania
    static ProjectionType projectionType; ///< Aktualny typ rzutowania

    /**
     * @brief Metoda wy�wietlaj�ca
     *
     * Metoda statyczna u�ywana jako funkcja wy�wietlaj�ca w OpenGL
     */
    static void display();

    /**
     * @brief Metoda zmieniaj�ca rozmiar okna
     *
     * Metoda statyczna wywo�ywana po zmianie rozmiaru okna
     *
     * @param[in] w Nowa szeroko�� okna
     * @param[in] h Nowa wysoko�� okna
     */
    static void reshape(int w, int h);

    /**
     * @brief Obs�uga zdarze� klawiatury
     *
     * Metoda statyczna obs�uguj�ca zdarzenia klawiatury
     *
     * @param[in] key Kod klawisza
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void keyboard(unsigned char key, int x, int y);

    /**
     * @brief Obs�uga specjalnych klawiszy
     *
     * Metoda statyczna obs�uguj�ca specjalne klawisze klawiatury
     *
     * @param[in] key Kod specjalnego klawisza
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void specialKeys(int key, int x, int y); //obsluga klawiszy do poruszania kamera

    /**
     * @brief Obs�uga zdarze� myszy
     *
     * Metoda statyczna obs�uguj�ca zdarzenia myszy
     *
     * @param[in] button Kod przycisku myszy
     * @param[in] state Stan przycisku myszy
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void mouse(int button, int state, int x, int y);

    /**
     * @brief Obs�uga zdarze� zegarowych
     *
     * Metoda statyczna wywo�ywana przez zegar programu
     *
     * @param[in] value Dodatkowa warto�� przekazywana przez zegar
     */
    static void timer(int value);

    /**
     * @brief Sprawdza klikni�cie przycisku
     *
     * Metoda prywatna sprawdzaj�ca klikni�cie przycisku w panelu sterowania
     *
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void checkButtonClick(int x, int y);

    /**
     * @brief Aktualizuje logik� silnika
     *
     * Metoda prywatna aktualizuj�ca logik� gry, wywo�ywana w p�tli g��wnej
     */
    void update();

    /**
     * @brief Metoda zwracaj�ca tryb wy�wietlania
     *
     * Metoda prywatna zwracaj�ca aktualnie ustawiony tryb wy�wietlania
     *
     * @return Aktualny tryb wy�wietlania
     */
    int getDisplayMode();
    

    /**
     * @brief Konstruktor inicjalizuj�cy
     *
     * Konstruktor inicjalizuj�cy silnik, przygotowuj�cy �rodowisko OpenGL
     *
     * @param[in] argc Liczba argument�w wiersza polece�
     * @param[in] argv Tablica argument�w wiersza polece�
     */
    Engine(int argc, char** argv) : pyramid(4.0f), windowId(-1), fullscreen(false), width(800), height(600), fps(60), useMouse(true),
                                    useKeyboard(true), doubleBuffering(true), useDepthBuffer(true), running(true), lightEnabled(false), flatShading(false) {
        glutInit(&argc, argv);
    }

    /**
     * @brief Metoda rysuj�ca panel sterowania
     *
     * Metoda prywatna rysuj�ca panel sterowania interfejsem u�ytkownika
     */
    void drawControlPanel();

public:
    

    /**
     * @brief Wska�nik na instancj� silnika.
     *
     * Wska�nik na jedyn� instancj� silnika graficznego.
     */
    static Engine* engineInstance;
  
    /**
     * @brief Metoda uzyskuj�ca instancj� silnika
     *
     * Metoda statyczna zwracaj�ca instancj� silnika, tworz�c j� je�li nie istnieje
     *
     * @param[in] argc Liczba argument�w wiersza polece�
     * @param[in] argv Tablica argument�w wiersza polece�
     * @return Referencja do instancji silnika
     */
    static Engine& getInstance(int argc, char** argv);

    /**
     * @brief Ustawia tryb pe�noekranowy
     *
     * Ustawia tryb pe�noekranowy dla okna aplikacji
     *
     * @param[in] fullscreen Flaga okre�laj�ca, czy aplikacja ma dzia�a� w trybie pe�noekranowym
     */
    void setFullscreen(bool fullscreen) {
        this->fullscreen = fullscreen;
    }

    /**
     * @brief Ustawia rozmiar okna aplikacji
     *
     * Ustawia nowy rozmiar okna aplikacji
     *
     * @param[in] width Nowa szeroko�� okna
     * @param[in] height Nowa wysoko�� okna
     */
    void setWindowSize(int width, int height) {
        this->width = width;
        this->height = height;
    }

    /**
     * @brief Ustawia kolor czyszczenia t�a
     *
     * Ustawia kolor, kt�ry zostanie u�yty podczas czyszczenia t�a ekranu
     *
     * @param[in] r Sk�adowa czerwona koloru (0.0 - 1.0)
     * @param[in] g Sk�adowa zielona koloru (0.0 - 1.0)
     * @param[in] b Sk�adowa niebieska koloru (0.0 - 1.0)
     * @param[in] a Sk�adowa alpha koloru (przezroczysto��, 0.0 - 1.0)
     */
    void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Zwraca sk�adow� czerwon� koloru czyszczenia
     *
     * Zwraca sk�adow� czerwon� koloru, kt�ry jest u�ywany do czyszczenia t�a
     *
     * @return Sk�adowa czerwona koloru czyszczenia
     */
    static GLfloat getRed() {
        return clearColor[0];
    }

    /**
     * @brief Zwraca sk�adow� zielon� koloru czyszczenia
     *
     * Zwraca sk�adow� zielon� koloru, kt�ry jest u�ywany do czyszczenia t�a
     *
     * @return Sk�adowa zielona koloru czyszczenia
     */
    static GLfloat getGreen() {
        return clearColor[1];
    }

    /**
     * @brief Zwraca sk�adow� niebiesk� koloru czyszczenia
     *
     * Zwraca sk�adow� niebiesk� koloru, kt�ry jest u�ywany do czyszczenia t�a
     *
     * @return Sk�adowa niebieska koloru czyszczenia
     */
    static GLfloat getBlue() {
        return clearColor[2];
    }

    /**
     * @brief Zwraca sk�adow� alpha koloru czyszczenia
     *
     * Zwraca sk�adow� alpha koloru, kt�ra okre�la przezroczysto�� podczas czyszczenia t�a
     *
     * @return Sk�adowa alpha koloru czyszczenia
     */
    static GLfloat getAlpha() {
        return clearColor[3];
    }

    /**
     * @brief Uruchamia g��wn� p�tl� silnika
     *
     * Metoda uruchamia g��wn� p�tl� programu, w kt�rej obs�ugiwane s� wszystkie zdarzenia i rysowanie
     */
    void run() {
        glutMainLoop();
    }

    /**
     * @brief Ustawia ilo�� klatek na sekund�
     *
     * Ustawia po��dan� ilo�� klatek na sekund� dla silnika
     *
     * @param[in] fps Ilo�� klatek na sekund�
     */
    void setFPS(int fps) {
        this->fps = fps;
    }

    /**
     * @brief Zwraca aktualn� ilo�� klatek na sekund�
     *
     * Zwraca aktualnie ustawion� ilo�� klatek na sekund�
     *
     * @return Aktualna ilo�� klatek na sekund�
     */
    int getFPS() {
        return fps;
    }

    /**
     * @brief W��cza lub wy��cza obs�ug� myszy
     *
     * Ustawia flag� okre�laj�c�, czy obs�uga myszy ma by� w��czona
     *
     * @param[in] useMouse `true`, je�li ma by� w��czona obs�uga myszy, `false` w przeciwnym razie
     */
    void setMouseEnabled(bool useMouse) {
        this->useMouse = useMouse;
    }

    /**
     * @brief W��cza lub wy��cza obs�ug� klawiatury
     *
     * Ustawia flag� okre�laj�c�, czy obs�uga klawiatury ma by� w��czona
     *
     * @param[in] useKeyboard `true`, je�li ma by� w��czona obs�uga klawiatury, `false` w przeciwnym razie
     */
    void setKeyboardEnabled(bool useKeyboard) {
        this->useKeyboard = useKeyboard;
    }

    /**
     * @brief Ustawia tryb podw�jnego buforowania
     *
     * Ustawia flag� okre�laj�c�, czy ma by� u�ywane podw�jne buforowanie
     *
     * @param[in] doubleBuffering `true`, je�li ma by� u�ywane podw�jne buforowanie, `false` w przeciwnym razie
     */
    void setDoubleBuffering(bool doubleBuffering) {
        this->doubleBuffering = doubleBuffering;
    }

    /**
     * @brief Ustawia u�ywanie bufora g��boko�ci
     *
     * Ustawia flag� okre�laj�c�, czy ma by� u�ywany bufor g��boko�ci
     *
     * @param[in] useDepthBuffer `true`, je�li ma by� u�ywany bufor g��boko�ci, `false` w przeciwnym razie
     */
    void setDepthBuffer(bool useDepthBuffer) {
        this->useDepthBuffer = useDepthBuffer;
    }

    /**
     * @brief Tworzy g��wne okno aplikacji
     *
     * Metoda tworzy g��wne okno aplikacji o podanym tytule
     *
     * @param[in] title Tytu� okna aplikacji
     */
    void createWindow(const char* title);

    /**
     * @brief Ustawia typ rzutowania
     *
     * Ustawia aktualny typ rzutowania u�ywany podczas renderowania
     *
     * @param[in] type Typ rzutowania (perspektywiczne lub ortograficzne)
     */
    void setProjectionType(ProjectionType type) {
        projectionType = type;
    }

    /**
     * @brief Zwraca aktualny typ rzutowania
     *
     * Zwraca aktualnie ustawiony typ rzutowania u�ywany podczas renderowania
     *
     * @return Aktualny typ rzutowania
     */
    static ProjectionType getProjectionType() {
        return projectionType;
    }

    /**
     * @brief Zamyka silnik i zwalnia zasoby
     *
     * Metoda zamyka silnik, zwalniaj�c zasoby i ko�cz�c dzia�anie aplikacji
     */
    void close();

};

