
#include"Defs.h"
#include"GameObject.h"

void GameObject::initialize() {
	gameState = GameState::Play;
	std::cout << "initialize GameObject\n";
	initSDL(gWindow, gRenderer);
}

void GameObject::renderGame() {
	SDL_RenderClear(gRenderer);
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
				;
			}
			else {
				;
			}
		}
		renderGame();
	}
}
