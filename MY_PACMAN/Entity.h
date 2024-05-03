#pragma once
#ifndef ENTITY_H
#define ENTITY_H

//Entity class represent Pacman and Ghost

#include "Defs.h"
#include "Texture.h"
#include "Animation.h"

class Entity
{
public:
	Texture* entityTexture;
	int currentFrames = 0;
	SDL_Rect startPos;
	SDL_Rect currentPos;
	std::vector<SDL_Rect> clips; // lam sao de khoi tao cai nay // khoi tao theo totalFrames
	int entityType;
	//int x; // toa độ, đưa vào render
	//int y; => cho vao dst cua texture r
	bool turnAllows[4] = { true, true, true, true }; // right left up down
	int speed;
	int totalFrames;
	bool isAlive;
	int facing;


	Entity(int _entityType, SDL_Renderer* renderer);
	/*void setTexture(std::string imagePath, SDL_Renderer* renderer) {
		entityTexture->loadFromFile(imagePath, renderer);
	}*/
	void setEntityType(int _entityType) {
		entityType = _entityType;
	}
	void initFrames();
	void tick();
	void setFacing(int _facing) {
		facing = _facing;
	}
	void setStartPos(SDL_Rect _startPos) {
		startPos = _startPos;
	}
	void setTotalFrames(int _totalFrames) {
		totalFrames = _totalFrames;
	}
	void checkCollisionWithWalls(int _x, int _y); // modify turnAllows, tinh toan vi tri tren numberic board
	void move(SDL_Event& e);
	virtual void renderEntity(SDL_Renderer* renderer);
	void renderToStartPosition(SDL_Renderer* renderer);
	void resetTurnAllows();
	//int getNumericMapPos(int row, int col);
};



#endif ENTITY_H



