#include "MenuState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	// nothing for now
	/*for (int i = 0; i < menuButtons.size(); i++)
	{
		menuButtons[i]->update();
	}*/
	std::cout << "Menu update\n";
	playButton->update();
	/*playExtraButton->update();
	helpButton->update();
	settingButton->update();*/
}
void MenuState::render()
{
	// nothing for now
	/*for (int i = 0; i < menuButtons.size(); i++)
	{
		menuButtons[i]->draw();
	}*/
	std::cout << "Menu render\n";
	menuTexture.render();
	playButton->draw();
	/*playExtraButton->draw();
	helpButton->draw();
	settingButton->draw();*/
}

void MenuState::handleEvent(SDL_Event& event) {
	playButton->handleEvents(event);
	/*playExtraButton->handleEvents(event);
	helpButton->handleEvents(event);
	settingButton->handleEvents(event);*/
}

// tao va load anh va load button
// goi ham khoi tao cua button
bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	menuTexture.loadFromFile("Textures/Menu.png");
	std::cout << "ua ua sao k load dc anh\n";
	playButton = new Button("Textures/Button/playButton.png", 200, 200, playButtonOnClick);
	
	/*playExtraButton = new Button("Textures//Button//playExtraButton.png", 200, 300, playExtraButtonOnClick);
	helpButton = new Button("Textures//Button//helpButton.png", 200, 400, helpButtonOnClick);
	settingButton = new Button("Textures//Button//settingButton.png", 200, 500, settingButtonOnClick);*/
	return true;
}

// clean kieu goi ham huy
bool MenuState::onExit()
{
	//delete menuTexture;
	delete playButton;
	/*delete playExtraButton;
	delete helpButton;
	delete settingButton;*/
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::playButtonOnClick()
{
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "Play button clicked\n";
}
//void MenuState::playExtraButtonOnClick()
//{
//	std::cout << "Exit button clicked\n";
//}
//void MenuState::helpButtonOnClick()
//{
//	std::cout << "Help button clicked\n";
//}
//void MenuState::settingButtonOnClick()
//{
//	std::cout << "Setting button clicked\n";
//}