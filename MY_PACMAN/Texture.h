#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Common.h"
class Texture
{
	SDL_Texture* texture;
	SDL_Rect src; // phần ảnh sẽ render
	SDL_Rect dst; // phần màn hình ảnh sẽ được render lên
public:
	Texture(std::string imagePath, const SDL_Rect& _src, const SDL_Rect& _dst, SDL_Renderer* renderer);
	~Texture();
	void setSrc(SDL_Rect& _src);
	void setDst(SDL_Rect& _dst);
	void render(SDL_Renderer* renderer);
	void setColor(SDL_Color color); 
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(uint8_t alpha);
};

#endif TEXTURE_H
