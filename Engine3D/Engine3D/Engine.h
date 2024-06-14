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
 * @brief Klasa reprezentuj¹ca silnik graficzny
 *
 * Klasa `Engine` zarz¹dza g³ówn¹ pêtl¹ programu oraz interakcj¹ z OpenGL
 */
class Engine {

private:
    int  windowId; ///< Identyfikator okna OpenGL
    bool fullscreen; ///< Flaga okreœlaj¹ca, czy aplikacja dzia³a w trybie pe³noekranowym
    int  width; ///< Szerokoœæ okna
    int  height; ///< Wysokoœæ okna
    int  fps; ///< Oczekiwana iloœæ klatek na sekundê
    bool useMouse; ///< Flaga okreœlaj¹ca, czy obs³uga myszy jest w³¹czona
    bool useKeyboard; ///< Flaga okreœlaj¹ca, czy obs³uga klawiatury jest w³¹czona
    bool doubleBuffering; ///< Flaga okreœlaj¹ca, czy u¿ywane jest podwójne buforowanie 
    bool useDepthBuffer; ///< Flaga okreœlaj¹ca, czy u¿ywane jest buforowanie g³êbokoœci
    bool running; ///< Flaga okreœlaj¹ca, czy silnik jest w trakcie dzia³ania
    Camera camera; ///< Obiekt kamery
    Pyramid pyramid; ///< Obiekt piramidy
    int engineMode; ///< Tryb pracy silnika
    bool lightEnabled; ///< Flaga okreœlaj¹ca, czy oœwietlenie jest w³¹czone
    bool flatShading; ///< Flaga okreœlaj¹ca, czy u¿ywane jest p³askie cieniowanie
    BitmapHandler textureHandler; ///< Obiekt do obs³ugi tekstur
    GLuint textureID; ///< Identyfikator tekstury OpenGL
      

    static GLfloat clearColor[4]; ///< Kolor czyszczenia t³a (RGBA)
    enum ProjectionType { PERSPECTIVE, ORTHOGRAPHIC }; ///< Typ wyliczeniowy do okreœlenia rodzaju rzutowania
    static ProjectionType projectionType; ///< Aktualny typ rzutowania

    /**
     * @brief Metoda wyœwietlaj¹ca
     *
     * Metoda statyczna u¿ywana jako funkcja wyœwietlaj¹ca w OpenGL
     */
    static void display();

    /**
     * @brief Metoda zmieniaj¹ca rozmiar okna
     *
     * Metoda statyczna wywo³ywana po zmianie rozmiaru okna
     *
     * @param[in] w Nowa szerokoœæ okna
     * @param[in] h Nowa wysokoœæ okna
     */
    static void reshape(int w, int h);

    /**
     * @brief Obs³uga zdarzeñ klawiatury
     *
     * Metoda statyczna obs³uguj¹ca zdarzenia klawiatury
     *
     * @param[in] key Kod klawisza
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void keyboard(unsigned char key, int x, int y);

    /**
     * @brief Obs³uga specjalnych klawiszy
     *
     * Metoda statyczna obs³uguj¹ca specjalne klawisze klawiatury
     *
     * @param[in] key Kod specjalnego klawisza
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void specialKeys(int key, int x, int y); //obsluga klawiszy do poruszania kamera

    /**
     * @brief Obs³uga zdarzeñ myszy
     *
     * Metoda statyczna obs³uguj¹ca zdarzenia myszy
     *
     * @param[in] button Kod przycisku myszy
     * @param[in] state Stan przycisku myszy
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void mouse(int button, int state, int x, int y);

    /**
     * @brief Obs³uga zdarzeñ zegarowych
     *
     * Metoda statyczna wywo³ywana przez zegar programu
     *
     * @param[in] value Dodatkowa wartoœæ przekazywana przez zegar
     */
    static void timer(int value);

    /**
     * @brief Sprawdza klikniêcie przycisku
     *
     * Metoda prywatna sprawdzaj¹ca klikniêcie przycisku w panelu sterowania
     *
     * @param[in] x Pozycja kursora x
     * @param[in] y Pozycja kursora y
     */
    static void checkButtonClick(int x, int y);

    /**
     * @brief Aktualizuje logikê silnika
     *
     * Metoda prywatna aktualizuj¹ca logikê gry, wywo³ywana w pêtli g³ównej
     */
    void update();

    /**
     * @brief Metoda zwracaj¹ca tryb wyœwietlania
     *
     * Metoda prywatna zwracaj¹ca aktualnie ustawiony tryb wyœwietlania
     *
     * @return Aktualny tryb wyœwietlania
     */
    int getDisplayMode();
    

    /**
     * @brief Konstruktor inicjalizuj¹cy
     *
     * Konstruktor inicjalizuj¹cy silnik, przygotowuj¹cy œrodowisko OpenGL
     *
     * @param[in] argc Liczba argumentów wiersza poleceñ
     * @param[in] argv Tablica argumentów wiersza poleceñ
     */
    Engine(int argc, char** argv) : pyramid(4.0f), windowId(-1), fullscreen(false), width(800), height(600), fps(60), useMouse(true),
                                    useKeyboard(true), doubleBuffering(true), useDepthBuffer(true), running(true), lightEnabled(false), flatShading(false) {
        glutInit(&argc, argv);
    }

    /**
     * @brief Metoda rysuj¹ca panel sterowania
     *
     * Metoda prywatna rysuj¹ca panel sterowania interfejsem u¿ytkownika
     */
    void drawControlPanel();

public:
    

    /**
     * @brief WskaŸnik na instancjê silnika.
     *
     * WskaŸnik na jedyn¹ instancjê silnika graficznego.
     */
    static Engine* engineInstance;
  
    /**
     * @brief Metoda uzyskuj¹ca instancjê silnika
     *
     * Metoda statyczna zwracaj¹ca instancjê silnika, tworz¹c j¹ jeœli nie istnieje
     *
     * @param[in] argc Liczba argumentów wiersza poleceñ
     * @param[in] argv Tablica argumentów wiersza poleceñ
     * @return Referencja do instancji silnika
     */
    static Engine& getInstance(int argc, char** argv);

    /**
     * @brief Ustawia tryb pe³noekranowy
     *
     * Ustawia tryb pe³noekranowy dla okna aplikacji
     *
     * @param[in] fullscreen Flaga okreœlaj¹ca, czy aplikacja ma dzia³aæ w trybie pe³noekranowym
     */
    void setFullscreen(bool fullscreen) {
        this->fullscreen = fullscreen;
    }

    /**
     * @brief Ustawia rozmiar okna aplikacji
     *
     * Ustawia nowy rozmiar okna aplikacji
     *
     * @param[in] width Nowa szerokoœæ okna
     * @param[in] height Nowa wysokoœæ okna
     */
    void setWindowSize(int width, int height) {
        this->width = width;
        this->height = height;
    }

    /**
     * @brief Ustawia kolor czyszczenia t³a
     *
     * Ustawia kolor, który zostanie u¿yty podczas czyszczenia t³a ekranu
     *
     * @param[in] r Sk³adowa czerwona koloru (0.0 - 1.0)
     * @param[in] g Sk³adowa zielona koloru (0.0 - 1.0)
     * @param[in] b Sk³adowa niebieska koloru (0.0 - 1.0)
     * @param[in] a Sk³adowa alpha koloru (przezroczystoœæ, 0.0 - 1.0)
     */
    void setClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    /**
     * @brief Zwraca sk³adow¹ czerwon¹ koloru czyszczenia
     *
     * Zwraca sk³adow¹ czerwon¹ koloru, który jest u¿ywany do czyszczenia t³a
     *
     * @return Sk³adowa czerwona koloru czyszczenia
     */
    static GLfloat getRed() {
        return clearColor[0];
    }

    /**
     * @brief Zwraca sk³adow¹ zielon¹ koloru czyszczenia
     *
     * Zwraca sk³adow¹ zielon¹ koloru, który jest u¿ywany do czyszczenia t³a
     *
     * @return Sk³adowa zielona koloru czyszczenia
     */
    static GLfloat getGreen() {
        return clearColor[1];
    }

    /**
     * @brief Zwraca sk³adow¹ niebiesk¹ koloru czyszczenia
     *
     * Zwraca sk³adow¹ niebiesk¹ koloru, który jest u¿ywany do czyszczenia t³a
     *
     * @return Sk³adowa niebieska koloru czyszczenia
     */
    static GLfloat getBlue() {
        return clearColor[2];
    }

    /**
     * @brief Zwraca sk³adow¹ alpha koloru czyszczenia
     *
     * Zwraca sk³adow¹ alpha koloru, która okreœla przezroczystoœæ podczas czyszczenia t³a
     *
     * @return Sk³adowa alpha koloru czyszczenia
     */
    static GLfloat getAlpha() {
        return clearColor[3];
    }

    /**
     * @brief Uruchamia g³ówn¹ pêtlê silnika
     *
     * Metoda uruchamia g³ówn¹ pêtlê programu, w której obs³ugiwane s¹ wszystkie zdarzenia i rysowanie
     */
    void run() {
        glutMainLoop();
    }

    /**
     * @brief Ustawia iloœæ klatek na sekundê
     *
     * Ustawia po¿¹dan¹ iloœæ klatek na sekundê dla silnika
     *
     * @param[in] fps Iloœæ klatek na sekundê
     */
    void setFPS(int fps) {
        this->fps = fps;
    }

    /**
     * @brief Zwraca aktualn¹ iloœæ klatek na sekundê
     *
     * Zwraca aktualnie ustawion¹ iloœæ klatek na sekundê
     *
     * @return Aktualna iloœæ klatek na sekundê
     */
    int getFPS() {
        return fps;
    }

    /**
     * @brief W³¹cza lub wy³¹cza obs³ugê myszy
     *
     * Ustawia flagê okreœlaj¹c¹, czy obs³uga myszy ma byæ w³¹czona
     *
     * @param[in] useMouse `true`, jeœli ma byæ w³¹czona obs³uga myszy, `false` w przeciwnym razie
     */
    void setMouseEnabled(bool useMouse) {
        this->useMouse = useMouse;
    }

    /**
     * @brief W³¹cza lub wy³¹cza obs³ugê klawiatury
     *
     * Ustawia flagê okreœlaj¹c¹, czy obs³uga klawiatury ma byæ w³¹czona
     *
     * @param[in] useKeyboard `true`, jeœli ma byæ w³¹czona obs³uga klawiatury, `false` w przeciwnym razie
     */
    void setKeyboardEnabled(bool useKeyboard) {
        this->useKeyboard = useKeyboard;
    }

    /**
     * @brief Ustawia tryb podwójnego buforowania
     *
     * Ustawia flagê okreœlaj¹c¹, czy ma byæ u¿ywane podwójne buforowanie
     *
     * @param[in] doubleBuffering `true`, jeœli ma byæ u¿ywane podwójne buforowanie, `false` w przeciwnym razie
     */
    void setDoubleBuffering(bool doubleBuffering) {
        this->doubleBuffering = doubleBuffering;
    }

    /**
     * @brief Ustawia u¿ywanie bufora g³êbokoœci
     *
     * Ustawia flagê okreœlaj¹c¹, czy ma byæ u¿ywany bufor g³êbokoœci
     *
     * @param[in] useDepthBuffer `true`, jeœli ma byæ u¿ywany bufor g³êbokoœci, `false` w przeciwnym razie
     */
    void setDepthBuffer(bool useDepthBuffer) {
        this->useDepthBuffer = useDepthBuffer;
    }

    /**
     * @brief Tworzy g³ówne okno aplikacji
     *
     * Metoda tworzy g³ówne okno aplikacji o podanym tytule
     *
     * @param[in] title Tytu³ okna aplikacji
     */
    void createWindow(const char* title);

    /**
     * @brief Ustawia typ rzutowania
     *
     * Ustawia aktualny typ rzutowania u¿ywany podczas renderowania
     *
     * @param[in] type Typ rzutowania (perspektywiczne lub ortograficzne)
     */
    void setProjectionType(ProjectionType type) {
        projectionType = type;
    }

    /**
     * @brief Zwraca aktualny typ rzutowania
     *
     * Zwraca aktualnie ustawiony typ rzutowania u¿ywany podczas renderowania
     *
     * @return Aktualny typ rzutowania
     */
    static ProjectionType getProjectionType() {
        return projectionType;
    }

    /**
     * @brief Zamyka silnik i zwalnia zasoby
     *
     * Metoda zamyka silnik, zwalniaj¹c zasoby i koñcz¹c dzia³anie aplikacji
     */
    void close();

};

