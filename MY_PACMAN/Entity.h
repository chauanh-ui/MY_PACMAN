#pragma once
#ifndef ENTITY_H
#define ENTITY_H

//Entity class represent Pacman and Ghost

#include "Texture.h"
#include "Position.h"
#include "Globals.h"
#include "Common.h"


class Entity : public Position {
public:
	Entity(EntityType MyIdentity);

	// return identity: pac or ghost
	unsigned char GetIdentity();

	// return speed
	unsigned char GetSpeed();

	// return direction
	unsigned char GetDirection();

	// return facing
	unsigned char GetFacing();

	bool IsAlive();

	void ModSpeed(unsigned char NewSpeed);

	void ModDirection(unsigned char NewDirection);

	void ModFacing(unsigned char NewFacing);

	void ModLifeStatement(bool NewLifeStatement);

	// important
	void GetPossiblePosition(short& x, short& y, unsigned char mover);

	//important
	void CharBoardPos(unsigned char SideDir, Position& BoardPos, float cell_x, float cell_y);

	// important
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



