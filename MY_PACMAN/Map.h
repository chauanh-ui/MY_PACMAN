#pragma once
#ifndef MAP_H
#define MAP_H
#include "Defs.h"
#include "Common.h"
#include "Texture.h"

class Map
{
	Texture* mapTexture = nullptr;
	//unsigned char numericMap[];
	//void reset();
	//void loadNumericMap();
public:
	Map(SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer);
};

#endif // !MAP_H


