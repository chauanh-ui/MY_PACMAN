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
	std::cout << "het entering\n";
	return true;
}

void PlayState::handleEvent(SDL_Event& event) {
	std::cout << "enter playstate handle event\n";
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
	std::cout << "Het play state handle event\n";
}

void PlayState::update()
{
	std::cout << "enter playstate update\n";
	if (mGame.Process(GameTimer, mover, StartTicks)) {
		processSuccess = true;
	}
	std::cout << "Het play state update \n";
}

void PlayState::render()
{
	std::cout << "enter playstate render\n";
	if (processSuccess) {
		mGame.Draw(GameTimer, StartTicks);
	}
	std::cout << "Het playstate rneder \n";

}

bool PlayState::onExit()
{
	std::cout << "exiting PlayState\n";
	return true;
}