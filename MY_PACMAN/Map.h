#pragma once
#ifndef MAP_H
#define MAP_H
#include "Defs.h"
#include "Common.h"
#include "Texture.h"
#include <fstream>

class Map
{
	Texture* mapTexture = nullptr;
	Texture* smallFoodTexture = nullptr;
	unsigned char numericMap[TOTAL_BLOCK]; // mảng 1 chiều chứa các kí tự phân biệt các loại block
	//void reset();
	
public:
	Map(SDL_Renderer* renderer);
	void changeMapColor(SDL_Event& e);
	void draw(SDL_Renderer* renderer);
	void loadNumericMap(); // load dữ liệu từ string charMap vào mảng
};

#endif // !MAP_H


