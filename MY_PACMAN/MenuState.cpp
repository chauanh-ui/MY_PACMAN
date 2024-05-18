#include "MenuState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
#include "SettingState.h"
#include "ChooseMapColorState.h"
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
	playExtraButton->update();
	helpButton->update();
	//settingButton->update();
}
void MenuState::render()
{
	// nothing for now
	/*for (int i = 0; i < menuButtons.size(); i++)
	{
		menuButtons[i]->draw();
	}*/
	std::cout << "Menu render\n";
	menuTexture.render(-OffsetX, -OffsetY);
	playButton->draw();
	playExtraButton->draw();
	helpButton->draw();
	//settingButton->draw();
}

void MenuState::handleEvent(SDL_Event& event) {
	playButton->handleEvents(event);
	playExtraButton->handleEvents(event);
	helpButton->handleEvents(event);
	//settingButton->handleEvents(event);
}

// tao va load anh va load button
// goi ham khoi tao cua button
bool MenuState::onEnter()
{
	std::cout << "entering MenuState\n";
	menuTexture.loadFromFile("Textures/Menu.png");
	playButton = new Button("Textures/Button/playButton.png", 215, 479, playButtonOnClick);
	
	playExtraButton = new Button("Textures//Button//playExtraButton.png", 156, 559, playExtraButtonOnClick);
	helpButton = new Button("Textures//Button//helpButton.png", 219, 639, helpButtonOnClick);
	//settingButton = new Button("Textures/Button/settingButton.png", 200, 500, settingButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool MenuState::onExit()
{
	//delete menuTexture;
	/*delete playButton;
	playButton = nullptr;*/
	//delete playExtraButton;
	/*delete helpButton;
	helpButton = nullptr;
	delete settingButton;
	settingButton = nullptr;*/
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::playButtonOnClick()
{
	isPlayExtra = false;
	GameController::getStateMachine()->changeState(new PlayState());
	//std::cout << "Play button clicked\n";
}
void MenuState::playExtraButtonOnClick()
{
	isPlayExtra = true;
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "Exit button clicked\n";
}
void MenuState::helpButtonOnClick()
{
	std::cout << "Help button clicked\n";
	GameController::getStateMachine()->changeState(new HelpState());
}
//void MenuState::settingButtonOnClick()
//{
//	GameController::getStateMachine()->changeState(new SettingState());
//	std::cout << "Setting button clicked\n";
//}