
#include"Defs.h"
#include"GameObject.h"
#include "Entity.h"
void GameObject::initialize() {
	gameState = GameState::Play;
	std::cout << "initialize GameObject\n";
	initSDL(gWindow, gRenderer);
	map = new Texture(IMAGE_MAP_PATH, gRenderer);
	map->setColor(BLUE);
	map->setSrc(IMAGE_MAP_SRC);
	map->setDst(IMAGE_MAP_DST);
	std::cout << "Cbi khoi tao pacman";
	simplePacman = new Pacman(gRenderer);
}

void GameObject::renderGame() {
	//SDL_SetRenderDrawColor()
	SDL_RenderClear(gRenderer);
	map->render(gRenderer);
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
				/*map->changeMapColor(e);*/
				std::cout << "chuan bi chay ham move pacman\n";
				simplePacman->move(e);
			}
			else {
				;
			}
		}
		//std::cout << "chuan bi render game\n";
		renderGame();
	}
}
