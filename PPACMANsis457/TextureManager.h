#pragma once
#include<map>
#include "Texture.h"
using namespace std;

class TextureManager
{
private:
	map<string, Texture*> mapTexturas;
	Texture* textureManager;


	const string pathPacman = "Resources/AurelioSol.png";
	const string pathFantasma1 = "Resources/AZULGR.png";
	const string pathFantasma2 = "Resources/VERDEGR.png";
	const string pathFantasma3 = "Resources/NARANJAGR.png";
	const string pathFantasma4 = "Resources/PLOMOGR.png";
	const string pathFruta = "Resources/Frutas.png";
	const string pathMoneda = "Resources/Monedas.png";
	const string pathSuperMoneda = "Resources/SuperMoneda.png";
	const string pathPared = "Resources/Muro.png";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;
public:
	TextureManager();
	~TextureManager();

	Texture* getTexture(string _key) { return mapTexturas[_key]; }
	void addTexture(string _key, Texture* _texture);
	void free();

	
};

