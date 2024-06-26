#pragma once
#ifndef GAME_H
#define GAME_H
#include "Common.h"
#include "Ghost.h"
#include "Timer.h"
#include "Sound.h"
#include "Board.h"
#include "Pac.h"
#include "Inky.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Fruit.h"
#include "AddedGhost.h"

class Game {
public:
	Game();
	~Game();
	void ResetGhostsLifeStatement();
	void ResetGhostsFacing();
	void Start();
	void ModStartStatement(bool NewStartStatement);
	void Clock();
	void UpdatePositions(std::vector<unsigned char>& mover, bool TimedStatus);
	void Food();
	void EntityCollisions();

	void Update(std::vector<unsigned char>& mover);
	unsigned short GetLevel();
	void IncreaseLevel();

	void UpdateDifficulty();

	bool IsLevelCompleted();

	void ClearMover(std::vector<unsigned char>& mover);
	void DeadlyPacGhostColl();
	void DeadlyGhostPacColl(Ghost& mGhost);
	void ModToWaka(bool NewWaka);
	void DeathSound();
	void ModDeathSoundStatement(bool NewDeathSoundStatement);

	void DrawLittleScore();

	bool Process(Timer& GameTimer, std::vector<unsigned char>& mover, unsigned short& StartTicks);
	void Draw(Timer& GameTimer, unsigned short& StartTicks);
	Sound mSound;
private:
	/*PlayMode playMode;
	
	MapTheme mapTheme;
	PacType pacType;
	MapColor mapColor;*/


	Board mBoard;
	Pac mPac;
	Blinky mBlinky;
	Inky mInky;
	Pinky mPinky;
	Clyde mClyde;
	
	AddedGhost addedGhost;

	Fruit mFruit;
	Timer MapAnimationTimer;
	LTexture Ready;
	LTexture GameOverTexture;

	// manage the whole game through actual map
	// vay phai update cai nay
	unsigned char ActualMap[BoardHeight * BoardWidth];


	bool IsGameStarted;

	bool IsGameOver;


	Timer GhostTimer;

	unsigned short ScatterTime;
	unsigned short ChasingTime;
	unsigned short GhostTimerTarget;
	bool TimedStatus;
	unsigned short Scorer;

	std::vector<Timer> LittleScoreTimer;
	std::vector<Position> LittleScorePositions;
	std::vector<unsigned short> LittleScoreScorers;

	unsigned short LittleTimerTarget;
	unsigned short Level;
	bool IsToScatterSound;
	bool IsToWakaSound;
	Timer WakaTimer;
	bool IsToDeathPacSound;
	unsigned char DeadGhostsCounter;
};

#endif GAME_H