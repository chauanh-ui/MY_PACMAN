#pragma once
#ifndef BASEOBJECT_H
#define BASEOBJECT_H

//Entity class represent Pacman and Ghost

#include "Defs.h"
#include "Texture.h"

class BaseObject {
protected:
	Texture* texture;
	int x; // toa do x, y se dc update khi di chuyen
	int y; // the x, y coordinates will be updated when call move functions
	int speed;
	int currentFrame; // index for clips
	int numberOfFrames;
	bool turnAllows[4] = { true, true, true, true };
	SDL_Point center; // toa do cua diem center
	SDL_Point startPosision; // toa do tren map khi bat dau
public:
	BaseObject();
	BaseObject(const std::string imagePath, SDL_Renderer* renderer);
	~BaseObject();
	int getStartX();
	int getStartY();

	void tick();

	void checkCollisionWithWalls(int _x, int _y);

	void renderObject(SDL_Renderer* renderer, SDL_Rect* clip, double angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void resetTurnAllows();
};


#endif BASEOBJECT_H