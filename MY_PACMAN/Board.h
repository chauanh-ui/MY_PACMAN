#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Texture.h"
#include "Entity.h"
#include "Timer.h"
class Board {
public:
	Board();
	~Board();
	void ConvertSketch();
	void CopyBoard(unsigned char ActualMap[]);
	void ResetPosition(Entity& ThisEntity);
	void SetScore();
	void SetHighScore();
	bool IsExtraLife();
	void IncreaseLives();
	void DecreaseLives();
	void ScoreIncrease(unsigned short Scorer);
	unsigned char GetLives();
	void Draw(unsigned char ActualMap[], Timer MapAnimationTimer);
	static void setMapColor(MapColor _mapColor);
private:
	static MapColor mapColor;

	LTexture WallTexture;

	LTexture MapTexture;
	LTexture PelletTexture;
	LTexture EnergizerTexture;
	LTexture DoorTexture;
	LTexture LivesTexture;
	LTexture ScoreWordTexture;
	LTexture ScoreTexture;
	LTexture HighScoreWordTexture;
	LTexture HighScoreTexture;
	unsigned char NumericBoard[BoardHeight * BoardWidth];
	unsigned int Score;
	bool IsExtra;
	char Lives;
};

#endif BOARD_H