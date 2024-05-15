#pragma once
#include "Ghost.h"
#include "Position.h"
#include "Pac.h"
class Clyde : public Ghost {
public:
	Clyde();
	void CalculateTarget(Position mPac);
	void UpdatePos(unsigned char ActualBoard[], Pac& mPac, bool TimedStatus);
};