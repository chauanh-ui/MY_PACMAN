#include "GameController.h"
#include "MenuState.h"
#include "PlayState.h"


//void GameController::initialize() {
//	InitializeSDL();
//
//}

void GameController::init() {
	m_pGameStateMachine = new GameStateMachine();
	//m_pGameStateMachine->changeState(new MenuState());
	m_pGameStateMachine->changeState(new PlayState());
}

void GameController::running() {
	/*mover.push_back(Right);
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
	}*/
}

void GameController::handleEvents() {
	//if (event.type == SDL_KEYDOWN &&  event.key.keysym.sym)
}


void GameController::update()
{
	m_pGameStateMachine->update();
}


void GameController::render()
{
	SDL_RenderClear(renderer);
	m_pGameStateMachine->render();
	SDL_RenderPresent(renderer);
}

//void GameController::close() {
//	CloseSDL();
//}