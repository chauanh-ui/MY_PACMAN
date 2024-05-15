#pragma once
#ifndef BLINKY_H
#define BLINKY_H

#include "Ghost.h"
#include "Position.h"
#include "Pac.h"
class Blinky : public Ghost {
public:
	Blinky();
	void CalculateTarget(Position mPac);
	void UpdatePos(unsigned char ActualBoard[], Pac& mPac, bool TimedStatus);
};

#endif BLINKY_H






