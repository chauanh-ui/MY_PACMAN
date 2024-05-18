#include "MenuState.h"
#include "HelpState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
const std::string HelpState::s_menuID = "HelpState";

void HelpState::update()
{

	std::cout << "setting update\n";
	//chooseMapColorButton->update();
	backButton->update();

}
void HelpState::render()
{
	// nothing for now
	/*for (int i = 0; i < menuButtons.size(); i++)
	{
		menuButtons[i]->draw();
	}*/
	std::cout << "help state render\n";
	backButton->draw();
}

void HelpState::handleEvent(SDL_Event& event) {
	//chooseMapColorButton->handleEvents(event);
	backButton->handleEvents(event);

}

// tao va load anh va load button
// goi ham khoi tao cua button
bool HelpState::onEnter()
{
	std::cout << "entering setting\n";
	helpTexture.loadFromFile("Textures/Help.png");
	
	backButton = new Button("Textures/Button/backButton.png", 224, 665, backButtonOnClick);
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