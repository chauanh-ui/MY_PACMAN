//#include"Menu.h"
//
//Menu::Menu(SDL_Renderer* renderer) {
//	intro = loadImage(IMAGE_INTRO_PATH, renderer);
//	playButton = loadImage(PLAY_BUTTON_IMAGE_PATH, renderer);
//	playExtraButton = loadImage(PLAY_EXTRA_BUTTON_IMAGE_PATH, renderer);
//}
//
//Menu::~Menu() {
//	if (intro != nullptr) {
//		SDL_DestroyTexture(intro);
//	}
//	/*if (playButton0 != nullptr) {
//		SDL_DestroyTexture(playButton0);
//	}
//	if (playButton1 != nullptr) {
//		SDL_DestroyTexture(playButton1);
//	}*/
//}
//
//void Menu::renderIntro(GameState gameState, SDL_Renderer* renderer) {
//	if (gameState == GameState::Intro) {
//		SDL_RenderCopy(renderer, intro, NULL, NULL);
//		//SDL_RenderCopy(renderer, playButton0, NULL, &PLAY_BUTTON_POS);
//	}
//	/*else if (gameState == GameState::GameOver) {
//		SDL_RenderCopy(renderer, gameOver, NULL, NULL);
//	}*/
//	else {
//		std::cout << "UUUUUUUUUUUUUUUUUUUUUUUUU\n";
//		;
//	}
//}
//
//void Menu::renderPlayButton(SDL_Renderer* renderer) {
//	SDL_RenderCopy(renderer, playButton, NULL, &PLAY_BUTTON_POS);
//
//}
//
//void Menu::renderPlayExtraButton(SDL_Renderer* renderer) {
//	SDL_RenderCopy(renderer, playExtraButton, NULL, &PLAY_EXTRA_BUTTON_POS);
//
//}
//
//void Menu::render(GameState gameState, SDL_Renderer* renderer) {
//	SDL_RenderClear(renderer);
//	renderIntro(gameState, renderer);
//	if (isInsidePlayButton) {
//		renderPlayButton(renderer);
//	}
//	if (isInsidePlayExtraButton) {
//		renderPlayExtraButton(renderer);
//	}
//	SDL_RenderPresent(renderer);
//}