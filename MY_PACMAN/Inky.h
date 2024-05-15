#pragma once
#ifndef INKY_H
#define INKY_H
#include "Ghost.h"
#include "Common.h"
#include "Pac.h"
//class Inky : public Ghost {
//public:
//	Inky(SDL_Renderer* renderer);
//	~Inky();
//};

class Inky : public Ghost {
public:
	Inky();
	void CalculateTarget(Entity mPac, Position mBlinky);
	void UpdatePos(unsigned char ActualBoard[], Pac& mPac, Position mBlinky, bool TimedStatus);
};






#endif INKY_H


