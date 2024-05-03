#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Defs.h"
#include "Map.h"
#include "Entity.h"
#include "Pacman.h"
class GameObject {
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Event e;
	Texture* map;
	SDL_Color mapColor;

	Texture* smallDot;
	Texture* bigDot;
	Texture* testDot;
	//Pacman* simplePacman;
	Pacman* simplePacman;

public:
	GameState gameState;
	void initialize(); // lan luot gap cac ham khoi tao cua may con kia
	void renderGame(); // goi lam render cua cac con kia
	void running(); // vong while // game loop
	~GameObject();
};

#endif GAMEOBJECT_H