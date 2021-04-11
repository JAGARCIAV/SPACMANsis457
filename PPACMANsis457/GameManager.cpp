#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	gPacManSurface = nullptr;
	gFantasmaSurface = nullptr;
	gFantasma2Surface = nullptr;
	gFantasma3Surface = nullptr;
	gFantasma4Surface = nullptr;
	gFrutaSurface = nullptr;

	juego_en_ejecucion = true;
	pacman = new Pacman();
	fruta = new Fruta();
}

int GameManager::onExecute() {
	if (onInit() == false) {
		return -1;
	}

	srand(time(NULL));

	pacman->window = gWindow;
	pacman->renderer = gRenderer;
	pacman->screenSurface = gScreenSurface;
	pacman->pacmanSurface = gPacManSurface;

	fantasma.window = gWindow;
	fantasma.renderer = gRenderer;
	fantasma.screenSurface = gScreenSurface;
	fantasma.fantasmaSurface = gFantasmaSurface;

	fruta->window = gWindow;
	fruta->renderer = gRenderer;
	fruta->screenSurface = gScreenSurface;
	fruta->frutaSurface = gFrutaSurface;

	fantasma2.window = gWindow;
	fantasma2.renderer = gRenderer;
	fantasma2.screenSurface = gScreenSurface;
	fantasma2.fantasma2Surface = gFantasma2Surface;

	fantasma3.window = gWindow;
	fantasma3.renderer = gRenderer;
	fantasma3.screenSurface = gScreenSurface;
	fantasma3.fantasma3Surface = gFantasma3Surface;

	fantasma4.window = gWindow;
	fantasma4.renderer = gRenderer;
	fantasma4.screenSurface = gScreenSurface;
	fantasma4.fantasma4Surface = gFantasma4Surface;

	SDL_Event Event;

	while (juego_en_ejecucion) {
		while (SDL_PollEvent(&Event)) {
			onEvent(&Event);
			pacman->handleEvent(Event);
		}
		// Mover Pacman
		pacman->move();

		// Mover Fantasma
		fantasma.move();
		fantasma2.move();
		fantasma3.move();
		fantasma4.move();

		fruta->mostrar();
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		//Update screen

		onLoop();
		onRender();
		SDL_RenderPresent(gRenderer);
	}

	onCleanup();

	return 0;
}

bool GameManager::onInit() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{

			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}


			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);

			/*if ((gPacManSurface = loadMediaToSurface("Resources/PacMan_01.bmp")) == NULL) {
				return false;
			}*/

			if ((gPacManSurface = SDL_LoadBMP("Resources/PacMan_01.bmp")) == NULL) {
				return false;
			}

			if ((gFantasmaSurface = SDL_LoadBMP("Resources/Fantasma.bmp")) == NULL) {
				return false;
			}

			if ((gFantasma2Surface = SDL_LoadBMP("Resources/Fantasma2.bmp")) == NULL) {
				return false;
			}

			if ((gFantasma3Surface = SDL_LoadBMP("Resources/Fantasma3.bmp")) == NULL) {
				return false;
			}

			if ((gFantasma4Surface = SDL_LoadBMP("Resources/Fantasma4.bmp")) == NULL) {
				return false;
			}

			if ((gFrutaSurface = SDL_LoadBMP("Resources/Fruta01.bmp")) == NULL) {
				return false;
			}

			

		}
	}

	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};
void GameManager::onLoop() {};
void GameManager::onRender() {
	pacman->render();
	fantasma.render();
	fantasma2.render();
	fantasma3.render();
	fantasma4.render();
	fruta->render();
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	SDL_FreeSurface(gPacManSurface);
	SDL_FreeSurface(gFantasmaSurface);
	SDL_FreeSurface(gFantasma2Surface);
	SDL_FreeSurface(gFantasma3Surface);
	SDL_FreeSurface(gFantasma4Surface);
	SDL_FreeSurface(gFrutaSurface);

	SDL_Quit();
};
