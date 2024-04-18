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
	//Texture* smallFoodTexture = nullptr;
	//Pacman pacMan; // sau sẽ tạo 1 class riêng cho pacman
	//void reset();
	
public:
	unsigned char numericMap[TOTAL_BLOCK_Y][TOTAL_BLOCK_X]; // mảng 2 chiều chứa các kí tự phân biệt các loại block
	Map(SDL_Renderer* renderer);
	void changeMapColor(SDL_Event& e);
	void draw(SDL_Renderer* renderer);
	void loadNumericMap(); // load dữ liệu từ string charMap vào mảng
};

#endif // !MAP_H


