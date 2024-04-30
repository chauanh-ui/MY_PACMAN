#pragma once
#ifndef ENTITY_H
#define ENTITY_H

//Entity class represent Pacman and Ghost

#include "Defs.h"
#include "Texture.h"
#include "Animation.h"

class Entity
{
	Texture* entityTexture; // sau se thay bang animation
	SDL_Rect src = { 0, 0, 32, 32 };
	int entityType = PACMAN;
	SDL_Rect container = { 0, 0, 32, 32 }; // container là dst để load texture // dst
	SDL_Point center; // vị trí tâm của container để check collision
	std::string imagePath;
	bool turnAllows[4] = { true, true, true, true }; // right left up down
	int speed = 2;
public:
	Entity(SDL_Renderer* renderer, const int _entityType);
	void setContainer(SDL_Rect& _container);
	SDL_Rect getContainer(){ return container; };
	void checkCollisionWithWalls(int container_x, int container_y); // modify turnAllows, tinh toan vi tri tren numberic board
	void move(SDL_Event& e);
	void renderEntity(SDL_Renderer* renderer);
	void renderToStartPosition(SDL_Renderer* renderer);
	void resetTurnAllows();
	int getNumericMapPos(int row, int col);


};
#endif ENTITY_H



