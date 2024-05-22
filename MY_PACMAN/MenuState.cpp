#include "MenuState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
#include "HelpState.h"
#include "SettingState.h"
#include "ChooseMapColorState.h"
#include "ChooseMapThemeState.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	
	playButton->update();
	playExtraButton->update();
	helpButton->update();
	settingButton->update();
}
void MenuState::render()
{
	
	menuTexture.render(-OffsetX, -OffsetY);
	playButton->draw();
	playExtraButton->draw();
	helpButton->draw();
	settingButton->draw();
}

void MenuState::handleEvent(SDL_Event& event) {
	playButton->handleEvents(event);
	playExtraButton->handleEvents(event);
	helpButton->handleEvents(event);
	settingButton->handleEvents(event);
}

// tao va load anh va load button
// goi ham khoi tao cua button
bool MenuState::onEnter()
{
	menuTexture.loadFromFile("Textures/Menu.png");
	playButton = new Button("Textures/Button/playButton.png", 270, 534, playButtonOnClick);
	
	playExtraButton = new Button("Textures/Button/playExtraButton.png", 207, 477, playExtraButtonOnClick);
	helpButton = new Button("Textures/Button/helpButton.png", 270, 590, helpButtonOnClick);
	settingButton = new Button("Textures/Button/settingButton.png", 595, 607, settingButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool MenuState::onExit()
{
	return true;
}

void MenuState::playButtonOnClick()
{
	isPlayExtra = false;
	GameController::getStateMachine()->changeState(new ChooseMapColorState());
	//std::cout << "Play button clicked\n";
}
void MenuState::playExtraButtonOnClick()
{
	isPlayExtra = true;
	GameController::getStateMachine()->changeState(new ChooseMapThemeState());
	//std::cout << "Exit button clicked\n";
}
void MenuState::helpButtonOnClick()
{
	GameController::getStateMachine()->changeState(new HelpState());
}
void MenuState::settingButtonOnClick()
{
	GameController::getStateMachine()->changeState(new SettingState());
}