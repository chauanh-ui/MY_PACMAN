#pragma once
#ifndef ADDED_GHOST_H
#define ADDED_GHOST_H
#include "Ghost.h"
#include "Common.h"
#include "Pac.h"
//class Inky : public Ghost {
//public:
//	Inky(SDL_Renderer* renderer);
//	~Inky();
//};

class AddedGhost : public Ghost {
public:
	AddedGhost();
	void CalculateTarget(Entity mPac, Position mBlinky);
	void UpdatePos(unsigned char ActualBoard[], Pac& mPac, Position mBlinky, bool TimedStatus);
};

#endif ADDED_GHOST_H