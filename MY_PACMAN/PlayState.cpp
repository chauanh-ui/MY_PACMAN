#include "PlayState.h"
#include <iostream>
const std::string PlayState::s_playID = "PLAY";


// khoi tao
bool PlayState::onEnter()
{
	std::cout << "entering PlayState\n";
	mover.push_back(Right);
	GameTimer.Start();
	mGame.mSound.PlayIntro();
	return true;
}

void PlayState::handleEvent(SDL_Event& event) {
	if (event.key.state == SDL_PRESSED) {
		if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d))
			mover.push_back(Right);
		else if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w))
			mover.push_back(Up);
		else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a))
			mover.push_back(Left);
		else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s))
			mover.push_back(Down);
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
		mGame.Draw();
	}
}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}