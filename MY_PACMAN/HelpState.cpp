#include "MenuState.h"
#include "HelpState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
const std::string HelpState::s_menuID = "HelpState";

void HelpState::update()
{

	backButton->update();
	previousButton->update();
	nextButton->update();

}
void HelpState::render()
{
	
	std::cout << "help state render\n";
	helpTexture.render(-OffsetX, -OffsetY);
	ghosts[currentGhost].render(48 - OffsetX, 123 - OffsetY);
	backButton->draw();
	previousButton->draw();
	nextButton->draw();
}

void HelpState::handleEvent(SDL_Event& event) {
	//chooseMapColorButton->handleEvents(event);
	backButton->handleEvents(event);
	previousButton->handleEvents(event);
	nextButton->handleEvents(event);

}

// tao va load anh va load button
// goi ham khoi tao cua button
bool HelpState::onEnter()
{
	currentGhost = 0;
	helpTexture.loadFromFile("Textures/Help/Help.png");
	for (int i = 0; i < numberOfGhost; i++) {
		ghosts[i].loadFromFile("Textures/Help/" + std::to_string(i + 1) + ".png");
	}
	
	backButton = new Button("Textures/Button/backButton.png", 263, 584, backButtonOnClick);
	previousButton = new Button("Textures/Button/previous_button.png", 230, 515, previousButtonOnClick);
	nextButton = new Button("Textures/Button/next_button.png", 370, 515, nextButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool HelpState::onExit()
{
	//delete menuTexture;
	//delete chooseMapColorButton;
	/*delete playExtraButton;
	delete helpButton;*/
	std::cout << "exiting setting\n";
	return true;
}


void HelpState::backButtonOnClick()
{
	GameController::getStateMachine()->changeState(new MenuState());
	std::cout << "back button clicked\n";
}


void HelpState::previousButtonOnClick()
{
	currentGhost--;
	if (currentGhost < 0) {
		currentGhost = 0;
	}
}


void HelpState::nextButtonOnClick()
{
	currentGhost++;
	if (currentGhost > numberOfGhost - 1) {
		currentGhost = 0;
	}
}