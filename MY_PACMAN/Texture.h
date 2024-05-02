#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Common.h"
class Texture
{
	SDL_Texture* texture = nullptr;
	int w = 0;
	int h = 0;

public:
	Texture(const std::string imagePath, const SDL_Rect& _src, const SDL_Rect& _dst, SDL_Renderer* renderer);
	~Texture();
	void setSrc(SDL_Rect& _src);
	void setDst(SDL_Rect& _dst);
	void render(SDL_Renderer* renderer);
	void setColor(SDL_Color color); 
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(uint8_t alpha);
};

#endif TEXTURE_H
