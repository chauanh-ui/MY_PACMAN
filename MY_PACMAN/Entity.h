#pragma once
#ifndef ENTITY_H
#define ENTITY_H

//Entity class represent Pacman and Ghost

#include "Texture.h"
#include "Position.h"
#include "Globals.h"
#include "Common.h"
//class Entity
//{
//public:
//	Texture* entityTexture;
//	int currentFrames = 0;
//	SDL_Rect startPos;
//	SDL_Rect currentPos;
//	std::vector<SDL_Rect> clips; // lam sao de khoi tao cai nay // khoi tao theo totalFrames
//	int entityType;
//	//int x; // toa độ, đưa vào render
//	//int y; => cho vao dst cua texture r
//	bool turnAllows[4] = { true, true, true, true }; // right left up down
//	int speed;
//	int totalFrames;
//	bool isAlive;
//	int facing;
//
//
//	Entity(int _entityType, SDL_Renderer* renderer);
//	/*void setTexture(std::string imagePath, SDL_Renderer* renderer) {
//		entityTexture->loadFromFile(imagePath, renderer);
//	}*/
//	void setEntityType(int _entityType) {
//		entityType = _entityType;
//	}
//	void initFrames();
//	void tick();
//	void setFacing(int _facing) {
//		facing = _facing;
//	}
//	void setStartPos(SDL_Rect _startPos) {
//		startPos = _startPos;
//	}
//	void setTotalFrames(int _totalFrames) {
//		totalFrames = _totalFrames;
//	}
//	void checkCollisionWithWalls(int _x, int _y); // modify turnAllows, tinh toan vi tri tren numberic board
//	void move(SDL_Event& e);
//	virtual void renderEntity(SDL_Renderer* renderer);
//	void renderToStartPosition(SDL_Renderer* renderer);
//	void resetTurnAllows();
//	void move(int direction) {
//		switch (direction) {
//		case DIRECTION_UP: 
//			currentPos.y -= speed;
//			if (!turnAllows[DIRECTION_UP]) {
//				currentPos.y += speed;
//			}
//			break;
//		case DIRECTION_DOWN:
//			currentPos.y += speed;
//			if (!turnAllows[DIRECTION_DOWN]) {
//				currentPos.y -= speed;
//			}
//			break;
//		case DIRECTION_LEFT:
//			currentPos.x -= speed;
//			if (!turnAllows[DIRECTION_LEFT]) {
//				currentPos.x += speed;
//			}
//			break;
//		case DIRECTION_RIGHT:
//			currentPos.x += speed;
//			if (!turnAllows[DIRECTION_RIGHT]) {
//				currentPos.x -= speed;
//			}
//			break;
//		}
//		std::cout << "current pos sau khi goi ham move:" << std::endl;
//		std::cout << "X:" << currentPos.x << " Y: " << currentPos.y << std::endl;
//	}
//	//int getNumericMapPos(int row, int col);
//};

class Entity : public Position {
public:
	Entity(EntityType MyIdentity);
	unsigned char GetIdentity();
	unsigned char GetSpeed();
	unsigned char GetDirection();
	unsigned char GetFacing();
	bool IsAlive();
	void ModSpeed(unsigned char NewSpeed);
	void ModDirection(unsigned char NewDirection);
	void ModFacing(unsigned char NewFacing);
	void ModLifeStatement(bool NewLifeStatement);
	void GetPossiblePosition(short& x, short& y, unsigned char mover);
	void CharBoardPos(unsigned char SideDir, Position& BoardPos, float cell_x, float cell_y);
	bool WallCollision(short x, short y, unsigned char ActualMap[], bool CanUseDoor = 0);
	void Move(unsigned char mover);
	void CheckWrap();
	bool IsColliding(Position other);
private:
	unsigned char Identity;
	unsigned char Speed;
	unsigned char Direction;
	unsigned char Facing;
	bool LifeStatement;
};






#endif ENTITY_H



