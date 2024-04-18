
#include"Defs.h"
#include"GameObject.h"
#include "Entity.h"
void GameObject::initialize() {
	gameState = GameState::Play;
	std::cout << "initialize GameObject\n";
	initSDL(gWindow, gRenderer);
	map = new Map(gRenderer);
	simplePacman = new Entity(gRenderer, PACMAN);
}

void GameObject::renderGame() {
	//SDL_SetRenderDrawColor()
	SDL_RenderClear(gRenderer);
	map->draw(gRenderer);
	simplePacman->renderEntity(gRenderer);
	SDL_RenderPresent(gRenderer);
}

GameObject::~GameObject() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	Mix_CloseAudio();
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}

void GameObject::running() {
	//Uint32 preTimeRender = SDL_GetTicks();
	while (gameState != GameState::Quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				gameState = GameState::Quit;
				break;
			}
			else if (e.type == SDL_KEYDOWN) {
				map->changeMapColor(e);
				simplePacman->move(e);
			}
			else {
				;
			}
		}
	
		renderGame();
	}
}
