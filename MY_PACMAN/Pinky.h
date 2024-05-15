#pragma once
#ifndef PINKY_H
#define PINKY_H

#include "Ghost.h"
#include "Common.h"
#include "Pac.h"
class Pinky : public Ghost {
public:
	Pinky();
	void CalculateTarget(Entity mPac);
	void UpdatePos(unsigned char ActualBoard[], Pac& mPac, bool TimedStatus);
};

#endif PINKY_H