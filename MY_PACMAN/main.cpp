
//#include"GameObject.h"
//
//int main(int argc, char* argv[]) {
//	GameObject* game = new GameObject;
//	game->initialize();
//	game->running();
//	//game->renderGame();
//	waitUntilKeyPressed();
//	std::cout << "SUCCESS!\n";
//	delete game;
//	return 0;
//}
#pragma once
//#include "Common.h"
//#include "Globals.h"
//#include "Texture.h"
//#include "Timer.h"
//#include "Position.h"
//#include "Entity.h"
//#include "Pac.h"
//#include "Ghost.h"
//#include "Blinky.h"
//#include "Inky.h"
//#include "Pinky.h"
//#include "Clyde.h"
//#include "Fruit.h"
//#include "Board.h"
//#include "Sound.h"
//#include "Game.h"
#include "GameController.h"
int main(int argc, char* args[]) {

	/*InitializeSDL();

	Game mGame;
	Timer GameTimer;
	SDL_Event event;
	bool quit = false;
	unsigned short StartTicks = 4500;
	std::vector<unsigned char> mover;
	mover.push_back(Right);
	GameTimer.Start();
	mGame.mSound.PlayIntro();

	while (!quit) {

		double IterationStart = SDL_GetPerformanceCounter();

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT)
				quit = true;
			if (event.key.state == SDL_PRESSED) {
				if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d))			mover.push_back(Right);
				else if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)) 		mover.push_back(Up);
				else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a))	mover.push_back(Left);
				else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s))	mover.push_back(Down);
				if (mover.size() > 2)
					mover.erase(mover.begin() + 1);
			}
		}

		SDL_RenderClear(renderer);

		if (mGame.Process(GameTimer, mover, StartTicks)) {
			mGame.Draw();
			SDL_RenderPresent(renderer);
		}

		double IterationEnd = SDL_GetPerformanceCounter();
		double ElapsedSeconds = (IterationEnd - IterationStart) / (double)SDL_GetPerformanceFrequency();
		double Delay = 16.666f - (ElapsedSeconds * 1000.0f);
		if (Delay > 0)
			SDL_Delay(std::max(0, (int)Delay));

	}

	CloseSDL();

	return 0;*/
	InitializeSDL();
	GameController* gameController = new GameController();

	gameController->running();


	//gameController->init(); 
	//gameController->update();
	//gameController->render();



	CloseSDL();
	return 0;
}