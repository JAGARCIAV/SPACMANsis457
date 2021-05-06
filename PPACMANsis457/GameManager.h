#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <list>


#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Bruja.h"
#include "Moneda.h"
#include "Texture.h"
#include "MapGenerator.h"


using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 1625;
const int SCREEN_HEIGHT = 525;

class GameManager
{
private:
    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

    Pacman* pacmanAux;
    Fantasma* fantasmaAux;

public:
   // vector<GameObject*> actoresJuego;
    list<GameObject*> listaActoresJuego;

    MapGenerator* generadorNivelJuego;

public:
    GameManager();
    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onRendere();
    void onCleanup();

    template<class T>
    int getEscudoTranformado(T* _objeto) {
        return _objeto->getEscudo()*10;
    }
};


