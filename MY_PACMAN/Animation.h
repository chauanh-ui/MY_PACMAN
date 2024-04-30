#pragma once
#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

#include "Common.h"
#include <vector>
class Animation
{
	SDL_Texture* texture;
	SDL_Rect dst; // ph?n màn hình ?nh s? ???c render lên
	int currentFrame = 0;
	int numberOfFrames;
	std::vector<SDL_Rect> clips;
public:
	Animation(const std::string imagePath, const std::vector<SDL_Rect>& _clips, const SDL_Rect& _dst, SDL_Renderer* renderer);
	~Animation();
	void setSrc(SDL_Rect& _src); // hay la moi lan render xong set src
	void setDst(SDL_Rect& _dst);

	void tick() {
		currentFrame = (currentFrame + 1) % clips.size();
	}
	const SDL_Rect* getCurrentClip() const {
		return &(clips[currentFrame]);
	}
	void renderAnimation(SDL_Renderer* renderer);
	void setColor(SDL_Color color);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(uint8_t alpha);
};

#endif ANIMATION_H