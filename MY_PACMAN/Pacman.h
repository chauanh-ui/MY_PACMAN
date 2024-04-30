#pragma once
#ifndef PACMAN_H
#define PACMAN_H
#include "Entity.h"

class Pacman : public Entity {
	Animation* animation;
public:
	Pacman();
	void changeDirection(SDL_Event& e);
	void eat();
	void checkCollisionWithGhost();

};













#endif PACMAN_H

