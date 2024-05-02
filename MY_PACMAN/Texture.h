#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Common.h"
class Texture
{
	SDL_Texture* texture = nullptr;
	SDL_Rect src; // phan clip anh
	SDL_Rect dst; // phan anh render len man hinh
	double angle;
	//SDL_Point center;

public:
	//Texture(const std::string imagePath, const SDL_Rect& _src, const SDL_Rect& _dst, SDL_Renderer* renderer);
	Texture(std::string imagePath, SDL_Renderer* renderer);
	~Texture();
	/*void loadFromFile(const std::string imagePath, SDL_Renderer* renderer) {
		texture = loadImage(imagePath, renderer);
	}*/

	void setDst(SDL_Rect _dst) {
		dst = _dst;
	}
	void setSrc(SDL_Rect _src) {
		src = _src;
	}
	void setAngle(double _angle) {
		angle = _angle;
	}

	void render(SDL_Renderer* renderer, double angle = 0);

	void setColor(SDL_Color color); 
};

#endif TEXTURE_H
