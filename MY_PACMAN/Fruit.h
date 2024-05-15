#pragma once
#ifndef FRUIT_H
#define FRUIT_H

#include "Position.h"
#include "Texture.h"
#include "Timer.h"
#include "Common.h"
#include "Globals.h"
class Fruit : public Position {
public:
	Fruit();
	~Fruit();
	void ModCurrentFruit(unsigned short ActualActualLevel);
	void UpdateFoodCounter();
	bool IsEatable();
	unsigned short GetScoreValue();
	void StartScoreTimer();
	void ResetScoreTimer();
	bool CheckDespawn();
	void Despawn();
	void ResetFoodCounter();
	void Draw();
private:
	LTexture FruitTexture;
	Timer FruitTimer;
	Timer ScoreTimer;
	SDL_Rect FruitSpriteClips[FruitFrames];
	unsigned char CurrentFruit;
	unsigned short FruitDuration;
	unsigned char FoodCounter;
};

#endif FRUIT_H