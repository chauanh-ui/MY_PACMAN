#include "MenuState.h"
#include "SettingState.h"
#include "GameController.h"
#include <iostream>
#include "PauseState.h"

const std::string PauseState::s_menuID = "Pause";

void PauseState::update()
{
	std::cout << "update pause state\n";
}
void PauseState::render()
{
	pauseTexture.render(144, 315); 
}

void PauseState::handleEvent(SDL_Event& event) {
	if (event.key.state == SDL_PRESSED && (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_p)) {
		GameController::getStateMachine()->popState();
	}
}

// tao va load anh va load button
// goi ham khoi tao cua button
bool PauseState::onEnter()
{
	//pauseTexture.loadFromRenderText()
	pauseTexture.loadFromRenderedText("Paused", White);

	return true;
}

// clean kieu goi ham huy
bool PauseState::onExit()
{
	return true;
}
