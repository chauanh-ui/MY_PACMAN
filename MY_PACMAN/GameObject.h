#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Defs.h"
#include "Map.h"
#include "Entity.h"
#include "Pacman.h"
#include "Inky.h"
#include "Menu.h"

class GameObject {
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Event e;
	Menu* menu;
	Texture* map;
	SDL_Color mapColor;

	Texture* smallDot;
	Texture* bigDot;
	Texture* testDot;
	Inky* inky;
	//Pacman* simplePacman;
	Pacman* simplePacman;

public:
	GameState gameState;
	//void initialize(); // lan luot gap cac ham khoi tao cua may con kia
	//void renderGame(); // goi lam render cua cac con kia
	//void running(); // vong while // game loop
	//~GameObject();
	void initialize(); // khoi tao các nhân vật, hình ảnh,... trong game
	void renderGame(); // vẽ game lên màn hình
	void running(); // lần lượt gọi intro, play, ..
	void introGame();
	void play();
	//void gameOver();
	~GameObject();
};

#endif GAMEOBJECT_H