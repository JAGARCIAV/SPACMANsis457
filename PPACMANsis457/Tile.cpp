#include "Tile.h"


Tile::Tile() {
	posicionX = 0;
	posicionY = 0;

	pacman = nullptr;
	pacmanClasico = nullptr;
	pacmanGalactico = nullptr;


	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
}

Tile::Tile(int _x, int _y) {
	posicionX = _x;
	posicionY = _y;

	pacman = nullptr;
	pacmanClasico = nullptr;
	pacmanGalactico = nullptr;

	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
}

