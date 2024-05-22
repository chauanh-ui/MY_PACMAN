#include "PlayState.h"
#include "PauseState.h"
#include <iostream>
#include "GameController.h"
#include "MenuState.h"
const std::string PlayState::s_playID = "PLAY";


// khoi tao
bool PlayState::onEnter()
{
	mover.push_back(Right);
	GameTimer.Start();
	mGame.mSound.PlayIntro();
	return true;
}

void PlayState::handleEvent(SDL_Event& event) {
	if (event.key.state == SDL_PRESSED || event.type == SDL_KEYDOWN) {
		if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d))
			mover.push_back(Right);
		else if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w))
			mover.push_back(Up);
		else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a))
			mover.push_back(Left);
		else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)) {
			mover.push_back(Down);
		}	
		else if (event.key.keysym.sym == SDLK_p || event.key.keysym.sym == SDLK_SPACE) {
			GameController::getStateMachine()->pushState(new PauseState());
		}
		else if (event.key.keysym.sym == SDLK_g ) {
			GameController::getStateMachine()->changeState(new PlayState());
		}
		else if (event.key.keysym.sym == SDLK_ESCAPE) {
			GameController::getStateMachine()->changeState(new MenuState());
		}
			
		if (mover.size() > 2)
			mover.erase(mover.begin() + 1);
	}
}

void PlayState::update()
{
	if (mGame.Process(GameTimer, mover, StartTicks)) {
		processSuccess = true;
	}
}

void PlayState::render()
{
	if (processSuccess) {
		mGame.Draw(GameTimer, StartTicks);
	}

}

bool PlayState::onExit()
{
	return true;
}