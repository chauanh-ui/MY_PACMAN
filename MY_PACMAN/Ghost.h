//#ifndef GHOST_H
//#define GHOST_H
//
//#include "Entity.h"
//#include "Pacman.h"
//class Ghost : public Entity {
//public:
//	int currentEyesFrames = 0;
//	bool shouldTurn[4] = { false, false, false, false };
//	bool isFrighten = false;
//	SDL_Color ghostColor;
//	Texture* eyesTexture;
//	int ghostType;
//	std::vector<int> nextPossibleDirection;
//	std::vector<SDL_Rect> eyesClips;
//	int direction = DIRECTION_LEFT;
//	int distance[4] = { 0, 0, 0, 0 };
//	SDL_Point target;
//	SDL_Point home = { 0, 0 };
//	int timer = 0;
//
//
//
//	Ghost(SDL_Renderer* renderer);
//	~Ghost();
//	void resetDistance() {
//		for (int i = 0; i < 4; i++) {
//			distance[i] = 0;
//		}
//	}
//	void setIsFrighten(bool _isPanEnergized) {
//		isFrighten = _isPanEnergized;
//	}
//	void resetIsFrighten() {
//		isFrighten = false;
//	}
//
//	void setColor(const SDL_Color& _ghostColor, bool isFrighten = false) {
//		ghostColor = _ghostColor;
//		if (isFrighten) {
//			ghostColor = GHOST_FRIGHTEN_COLOR;
//		}
//	}
//
//	void setTarget(int _x, int _y) {
//		target.x = _x;
//		target.y = _y;
//	}
//
//	void setTextureColor() {
//		entityTexture->setColor(ghostColor);
//	}
//
//	void updateShouldTurn();
//	void resetShouldTurn() {
//		shouldTurn[0] = false;
//		shouldTurn[1] = false;
//		shouldTurn[2] = false;
//		shouldTurn[3] = false;
//	}
//	void initEyesFrames() {
//		eyesClips.resize(GHOST_EYE_FRAMES);
//		for (int i = 0; i < GHOST_EYE_FRAMES; i++) {
//			eyesClips[i].x = i * BLOCKSIZE32;
//			eyesClips[i].y = 0;
//			eyesClips[i].w = BLOCKSIZE32;
//			eyesClips[i].h = BLOCKSIZE32;
//		}
//	}
//
//	void renderGhost(SDL_Renderer* renderer);
//	void tickEyesFrames() {
//		currentEyesFrames = currentEyesFrames + 1;
//		if (currentEyesFrames / (GHOST_EYE_FRAMES - 1) >= (GHOST_EYE_FRAMES - 1)) {
//			currentEyesFrames = 0;
//		}
//	}
//
//	void updateDirection(int targetX, int targetY);
//	void moving(Pacman* pacman);
//	void moveGhost(SDL_Event& e);
//};
#pragma once
#ifndef GHOST_H
#define GHOST_H
#include "Common.h"
#include "Position.h"
#include "Globals.h"
#include "Entity.h"
#include "Timer.h"
#include "Pac.h"
class Ghost : public Entity {
public:
	Ghost(SDL_Color MyColor, EntityType MyIdentity);
	~Ghost();
	bool IsTargetToCalculate(Pac& mPac);
	void PossDirsBubbleSort(std::vector<float>& Distances, std::vector<unsigned char>& PossibleDirections);
	void CalculateDirection(unsigned char ActualMap[]);
	bool IsHome();
	void ModStatus(bool NewStatus);
	void UpdateStatus(Pac& mPac, bool TimedStatus);
	void UpdateFacing(Pac& mPac);
	void UpdateSpeed(Pac& mPac);
	void Draw(Pac& mPac, Timer mGhostTimer, unsigned short mTimerTarget);
	Position Target;
	Position ScatterTarget;
	Position DoorTarget;
	Position Home;
private:
	LTexture Body;
	LTexture Eyes;
	SDL_Rect GhostBodySpriteClips[GhostBodyFrames];
	SDL_Rect GhostEyeSpriteClips[GhostEyeFrames];
	SDL_Color Color;
	unsigned char CurrentBodyFrame;
	bool CanUseDoor;
	bool Status; // false -> chase	true -> scatter

	//bool isAddedGhost;
};

#endif GHOST_H


