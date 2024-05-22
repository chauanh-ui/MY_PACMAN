#include "MenuState.h"
#include "SettingState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
#include "MenuState.h"
const std::string SettingState::s_menuID = "SETTING";

void SettingState::update()
{
	
	//chooseMapColorButton->update();
	okButton->update();
	minusButton->update();
	addButton->update();
	
}
void SettingState::render()
{
	
	settingTexture.render(-OffsetX, -OffsetY);
	okButton->draw();
	minusButton->draw();
	addButton->draw();
	if (isGhostAdded) {
		greendyTexture.render(288-OffsetX,176 -OffsetY);
		addedGhostTexture.render(49-OffsetX,271 -OffsetY);
	}
}

void SettingState::handleEvent(SDL_Event& event) {
	//chooseMapColorButton->handleEvents(event);
	okButton->handleEvents(event);
	minusButton->handleEvents(event);
	addButton->handleEvents(event);
}

// tao va load anh va load button
// goi ham khoi tao cua button
bool SettingState::onEnter()
{
	settingTexture.loadFromFile("Textures/Setting/Setting.png");
	addedGhostTexture.loadFromFile("Textures/Setting/addGhost.png");
	greendyTexture.loadFromFile("Textures/Setting/greendy.png");
	
	okButton = new Button("Textures/Button/okButton.png", 263, 588, okButtonOnClick);
	minusButton = new Button("Textures/Button/minusButton.png", 438, 196, minusButtonOnClick);
	addButton = new Button("Textures/Button/addButton.png", 492, 187, addButtonOnClick);
	return true;
}

bool SettingState::onExit()
{
	
	return true;
}

void SettingState::addButtonOnClick()
{
	isGhostAdded = true;
}

void SettingState::minusButtonOnClick()
{
	isGhostAdded = false;
}


void SettingState::okButtonOnClick()
{
	GameController::getStateMachine()->changeState(new MenuState());
}