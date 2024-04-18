#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Common.h"
#include "Defs.h"
#include "Map.h"
#include "Entity.h"
class GameObject {
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Event e;
	Map* map;
	Entity* simplePacman;

public:
	GameState gameState;
	void initialize();
	void renderGame();
	void running();
	~GameObject();
};

#endif GAMEOBJECT_H