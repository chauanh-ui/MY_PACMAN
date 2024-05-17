#include "MenuState.h"
#include "ChooseMapColorState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
const std::string ChooseMapColorState::s_menuID = "CHOOSE_MAP_COLOR";

void ChooseMapColorState::update()
{
	
	std::cout << "cmc update\n";
	color_01_button->update();
	color_02_button->update();
	color_03_button->update();
	color_04_button->update();
	play_Button->update();
	backButton->update();
	
}
void ChooseMapColorState::render()
{
	// nothing for now
	/*for (int i = 0; i < menuButtons.size(); i++)
	{
		menuButtons[i]->draw();
	}*/
	std::cout << "cmc render\n";
	chooseMapColorTexture.render();
	color_01_button->draw();
	color_02_button->draw();
	color_03_button->draw();
	color_04_button->draw();
	play_Button->draw();
	backButton->draw();
}

void ChooseMapColorState::handleEvent(SDL_Event& event) {
	color_01_button->handleEvents(event);
	color_02_button->handleEvents(event);
	color_03_button->handleEvents(event);
	color_04_button->handleEvents(event);
	play_Button->handleEvents(event);
	backButton->handleEvents(event);

}

// tao va load anh va load button
// goi ham khoi tao cua button
bool ChooseMapColorState::onEnter()
{
	std::cout << "entering choose map color state\n";
	chooseMapColorTexture.loadFromFile("Textures/ChooseMapColor.png");
	color_01_button = new Button("Textures/Button/color_01_button.png", 200, 200, color_01_button_on_click);
	color_02_button = new Button("Textures/Button/color_02_button.png", 200, 300, color_02_button_on_click);
	color_03_button = new Button("Textures/Button/color_03_button.png", 200, 400, color_03_button_on_click);
	color_04_button = new Button("Textures/Button/color_04_button.png", 200, 500, color_04_button_on_click);

	play_Button = new Button("Textures/Button/playButton.png", 200, 100, play_ButtonOnClick);
	/*playExtraButton = new Button("Textures//Button//playExtraButton.png", 200, 300, playExtraButtonOnClick);
	helpButton = new Button("Textures//Button//helpButton.png", 200, 400, helpButtonOnClick);*/
	backButton = new Button("Textures/Button/backButton.png", 200, 600, backButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool ChooseMapColorState::onExit()
{
	//delete menuTexture;
	/*delete color_01_button;
	color_01_button = nullptr;
	delete color_02_button;
	color_02_button = nullptr;
	delete color_03_button;
	color_03_button = nullptr;
	delete color_04_button;
	color_04_button = nullptr;
	delete play_Button;
	play_Button = nullptr;
	delete backButton;
	backButton = nullptr;*/
	std::cout << "exiting ChooseMapColor\n";
	return true;
}

//void MenuState::playExtraButtonOnClick()
//{
//	std::cout << "Exit button clicked\n";
//}
//void MenuState::helpButtonOnClick()
//{
//	std::cout << "Help button clicked\n";
//}

void ChooseMapColorState::color_01_button_on_click()
{
	Board::setMapColor(MapColor::map_blue);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_01_button_on_click\n";
}
void ChooseMapColorState::color_02_button_on_click()
{
	Board::setMapColor(MapColor::map_green);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_02_button_on_click\n";
}
void ChooseMapColorState::color_03_button_on_click()
{
	Board::setMapColor(MapColor::map_pink);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_03_button_on_click\n";
}
void ChooseMapColorState::color_04_button_on_click()
{
	Board::setMapColor(MapColor::map_purple);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_04_button_on_click\n";
}
void ChooseMapColorState::backButtonOnClick()
{
	GameController::getStateMachine()->changeState(new MenuState());
	std::cout << "back button clicked\n";
}
void ChooseMapColorState::play_ButtonOnClick()
{
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "Play button clicked\n";
}