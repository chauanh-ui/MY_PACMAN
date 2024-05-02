#pragma once
#ifndef PACMAN_H
#define PACMAN_H
#include "Entity.h"

class Pacman : public Entity {
private:
	int score;
	bool isEnergize;
	int facing; // de xem no dang facing vs cai j, neu dang facing vs food thi an
	// facing hình như là trái phải trên dưới // cho vào để render đúng chiều


public:
	Pacman(SDL_Renderer* renderer);
	~Pacman();
	void eat();
	void move(SDL_Event& e);
	void checkCollisionWithGhost();
};













#endif PACMAN_H

