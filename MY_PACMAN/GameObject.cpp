
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

	smallDot = new Texture(SMALL_DOT_IMAGE_PATH, gRenderer);
	testDot = new Texture(BIG_DOT_IMAGE_PATH, gRenderer);
	bigDot = new Texture(BIG_DOT_IMAGE_PATH, gRenderer);
	smallDot->setSrc(DOT_IMAGE_SRC);
	bigDot->setSrc(DOT_IMAGE_SRC);
	testDot->setSrc(DOT_IMAGE_SRC);
	std::cout << "Cbi khoi tao pacman";
	simplePacman = new Pacman(gRenderer);
}

void GameObject::renderGame() {
	//SDL_SetRenderDrawColor()
	SDL_RenderClear(gRenderer);
	map->render(gRenderer);
	for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
			if (board[i][j] == PELLET) {
				SDL_Rect dst;
				dst.x = j * BLOCKSIZE16 + OFFSET_X + 4;
				dst.y = i * BLOCKSIZE16 + OFFSET_Y + 4;
				dst.w = 8;
				dst.h = 8;
				smallDot->setDst(dst);
				smallDot->render(gRenderer);
			}
			else if (board[i][j] == ENERGIZER) {
				SDL_Rect dst;
				dst.x = j * BLOCKSIZE16 + OFFSET_X;
				dst.y = i * BLOCKSIZE16 + OFFSET_Y;
				dst.w = BLOCKSIZE16;
				dst.h = BLOCKSIZE16;
				bigDot->setDst(dst);
				bigDot->render(gRenderer);
			}
			
		}
	}
	simplePacman->renderEntity(gRenderer);
	
	// test energize status
	if (simplePacman->getEnergizedStatus()) {
		SDL_Rect dst;
		dst.x = 0;
		dst.y = 0;
		dst.w = BLOCKSIZE16;
		dst.h = BLOCKSIZE16;
		testDot->setDst(dst);
		testDot->render(gRenderer);
	}
	SDL_RenderPresent(gRenderer);
}

GameObject::~GameObject() {
	delete map;
	delete smallDot;
	delete bigDot;
	delete testDot;
	delete simplePacman;
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
