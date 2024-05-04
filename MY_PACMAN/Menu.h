#pragma once
#ifndef MENU_H
#define MENU_H

#include"Defs.h"
#include"Common.h"

class Menu {
	SDL_Texture* intro;

	SDL_Texture* playButton;


	SDL_Texture* playExtraButton;
	
	SDL_Texture* help;
	SDL_Texture* quit;
	SDL_Texture* gameOver;
	bool isInsidePlayButton;
	bool isInsidePlayExtraButton;

public:
	Menu(SDL_Renderer* renderer);
	~Menu();
	void renderIntro(GameState gameState, SDL_Renderer* renderer);
	void renderPlayButton(SDL_Renderer* renderer);
	void render(GameState gameState, SDL_Renderer* renderer);
	void renderPlayExtraButton(SDL_Renderer* renderer);
	void setIsInsidePlayButton(bool _isInsidePlayButton) {
		isInsidePlayButton = _isInsidePlayButton;
	}

	void setIsInsidePlayExtraButton(bool _isInsidePlayExtraButton) {
		isInsidePlayExtraButton = _isInsidePlayExtraButton;
	}
	

};


#endif MENU_H