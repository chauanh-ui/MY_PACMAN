//
//#include"Defs.h"
//#include"GameObject.h"
//#include "Entity.h"
//void GameObject::initialize() {
//	gameState = GameState::Intro;
//	std::cout << "initialize GameObject\n";
//	initSDL(gWindow, gRenderer);
//	map = new Texture(IMAGE_MAP_PATH, gRenderer);
//	map->setColor(BLUE);
//	map->setSrc(IMAGE_MAP_SRC);
//	map->setDst(IMAGE_MAP_DST);
//
//	menu = new Menu(gRenderer);
//	smallDot = new Texture(SMALL_DOT_IMAGE_PATH, gRenderer);
//	testDot = new Texture(BIG_DOT_IMAGE_PATH, gRenderer);
//	bigDot = new Texture(BIG_DOT_IMAGE_PATH, gRenderer);
//	smallDot->setSrc(DOT_IMAGE_SRC);
//	bigDot->setSrc(DOT_IMAGE_SRC);
//	testDot->setSrc(DOT_IMAGE_SRC);
//	std::cout << "Cbi khoi tao pacman";
//	inky = new Inky(gRenderer);
//	simplePacman = new Pacman(gRenderer);
//}
//
//void GameObject::renderGame() {
//	//SDL_SetRenderDrawColor()
//	SDL_RenderClear(gRenderer);
//	//menu->render(gameState, gRenderer);
//	map->render(gRenderer);
//	for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
//		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
//			if (board[i][j] == PELLET) {
//				SDL_Rect dst;
//				dst.x = j * BLOCKSIZE16 + OFFSET_X + 4;
//				dst.y = i * BLOCKSIZE16 + OFFSET_Y + 4;
//				dst.w = 8;
//				dst.h = 8;
//				smallDot->setDst(dst);
//				smallDot->render(gRenderer);
//			}
//			else if (board[i][j] == ENERGIZER) {
//				SDL_Rect dst;
//				dst.x = j * BLOCKSIZE16 + OFFSET_X;
//				dst.y = i * BLOCKSIZE16 + OFFSET_Y;
//				dst.w = BLOCKSIZE16;
//				dst.h = BLOCKSIZE16;
//				bigDot->setDst(dst);
//				bigDot->render(gRenderer);
//			}
//			
//		}
//	}
//	inky->renderGhost(gRenderer);
//	simplePacman->renderEntity(gRenderer);
//	
//	// test energize status
//	if (simplePacman->getEnergizedStatus()) {
//		SDL_Rect dst;
//		dst.x = 0;
//		dst.y = 0;
//		dst.w = BLOCKSIZE16;
//		dst.h = BLOCKSIZE16;
//		testDot->setDst(dst);
//		testDot->render(gRenderer);
//	}
//	SDL_RenderPresent(gRenderer);
//}
//
//GameObject::~GameObject() {
//	delete menu;
//	delete map;
//	delete smallDot;
//	delete bigDot;
//	delete testDot;
//	delete simplePacman;
//	delete inky;
//	SDL_DestroyRenderer(gRenderer);
//	SDL_DestroyWindow(gWindow);
//	Mix_CloseAudio();
//	IMG_Quit();
//	TTF_Quit();
//	Mix_Quit();
//	SDL_Quit();
//}
//
//void GameObject::play() {
//	//Uint32 preTimeRender = SDL_GetTicks();
//	while (gameState == GameState::Play) {
//		while (SDL_PollEvent(&e) != 0) {
//			if (e.type == SDL_QUIT) {
//				gameState = GameState::Quit;
//				break;
//			}
//			else if (e.type == SDL_KEYDOWN) {
//				/*map->changeMapColor(e);*/
//				simplePacman->move(e);
//				inky->moveGhost(e);
//			}
//			else {
//				;
//			}
//		}
//		
//		//std::cout << "chuan bi render game\n";
//		renderGame();
//	}
//}
//
//void GameObject::running() {
//	while (gameState != GameState::Quit) {
//		introGame();
//		play();
//		//gameOver();
//	}
//}
//
//void GameObject::introGame() {
//	while (gameState == GameState::Intro) {
//		while (SDL_PollEvent(&e) != 0) {
//			if (e.type == SDL_QUIT) {
//				gameState = GameState::Quit;
//				break;
//			}
//			else if (e.type == SDL_MOUSEMOTION) {
//				int mouseX, mouseY;
//				SDL_GetMouseState(&mouseX, &mouseY);
//				std::cout << "Mouse x: " << mouseX << " MouseY: " << mouseY << std::endl;
//				if (mouseX > 252 && mouseX < 505 && mouseY > 459 && mouseY < 490) {
//					menu->setIsInsidePlayButton(true);
//				} else {	
//					menu->setIsInsidePlayButton(false);
//				}
//				if (mouseX > 308 && mouseX < 441 && mouseY > 508 && mouseY < 529) {
//					menu->setIsInsidePlayExtraButton(true);
//				} else {
//					menu->setIsInsidePlayExtraButton(false);
//				}
//			}
//			else if (e.type == SDL_MOUSEBUTTONDOWN) {
//				int mouseX, mouseY;
//				SDL_GetMouseState(&mouseX, &mouseY);
//				std::cout << "Mouse x: " << mouseX << " MouseY: " << mouseY << std::endl;
//				if (mouseX > 252 && mouseX < 505 && mouseY > 459 && mouseY < 490) {
//					gameState = GameState::Play;
//				}
//				if (mouseX > 300 && mouseX < 451 && mouseY > 501 && mouseY < 532) {
//					gameState = GameState::Play; // PlayExtra
//				}
//			}
//			else {
//				;
//			}
//		}
//		//renderGame();
//		menu->render(gameState, gRenderer);
//	}
//}
