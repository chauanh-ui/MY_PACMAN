
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

	smallDot = new Texture(DOT_IMAGE_PATH, gRenderer);
	smallDot->setSrc(DOT_IMAGE_SRC);

	std::cout << "Cbi khoi tao pacman";
	simplePacman = new Pacman(gRenderer);
}

void GameObject::renderGame() {
	//SDL_SetRenderDrawColor()
	SDL_RenderClear(gRenderer);
	map->render(gRenderer);
	std::cout << "WWWWWWWWWWWWWWWWWWWWWWWWW\n";
	for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
			
			if (board[i][j] == PELLET) {
				std::cout << "HHHHHHHHHHHHHHH\n";
				SDL_Rect dst;
				dst.x = j * BLOCKSIZE16 + OFFSET_X + 4;
				dst.y = i * BLOCKSIZE16 + OFFSET_Y + 4;
				dst.w = 8;
				dst.h = 8;
				smallDot->setDst(dst);
				smallDot->render(gRenderer);
			}
			
		}
	}
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
