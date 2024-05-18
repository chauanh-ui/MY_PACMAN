#include "MenuState.h"
#include "ChooseMapColorState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
const std::string ChooseMapColorState::s_menuID = "CHOOSE_MAP_COLOR";

void ChooseMapColorState::update()
{
	
	std::cout << "cmc update\n";
	blue_button->update();
	green_button->update();
	light_blue_button->update();
	red_button->update();
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
	chooseMapColorTexture.render(-OffsetX, -OffsetY);
	blue_button->draw();
	green_button->draw();
	light_blue_button->draw();
	red_button->draw();
	play_Button->draw();
	backButton->draw();
}

void ChooseMapColorState::handleEvent(SDL_Event& event) {
	blue_button->handleEvents(event);
	green_button->handleEvents(event);
	light_blue_button->handleEvents(event);
	red_button->handleEvents(event);
	play_Button->handleEvents(event);
	backButton->handleEvents(event);

}

// tao va load anh va load button
// goi ham khoi tao cua button
bool ChooseMapColorState::onEnter()
{
	std::cout << "entering choose map color state\n";
	chooseMapColorTexture.loadFromFile("Textures/ChooseMapColorState.png");
	blue_button = new Button("Textures/Button/blue_button.png", 39, 198, blue_button_on_click);
	green_button = new Button("Textures/Button/green_button.png", 294, 198, green_button_on_click);
	light_blue_button = new Button("Textures/Button/light_blue_button.png", 39, 434, light_blue_button_on_click);
	red_button = new Button("Textures/Button/red_button.png", 294,434 , red_button_on_click);

	//play_Button = new Button("Textures/Button/playButton.png", 200, 100, play_ButtonOnClick);
	/*playExtraButton = new Button("Textures//Button//playExtraButton.png", 200, 300, playExtraButtonOnClick);
	helpButton = new Button("Textures//Button//helpButton.png", 200, 400, helpButtonOnClick);*/
	backButton = new Button("Textures/Button/backButton.png", 230, 676, backButtonOnClick);
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

void ChooseMapColorState::blue_button_on_click()
{
	Board::setMapColor(MapColor::map_blue);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_01_button_on_click\n";
}
void ChooseMapColorState::green_button_on_click()
{
	Board::setMapColor(MapColor::map_green);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_02_button_on_click\n";
}
void ChooseMapColorState::light_blue_button_on_click()
{
	Board::setMapColor(MapColor::map_light_blue);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_03_button_on_click\n";
}
void ChooseMapColorState::red_button_on_click()
{
	Board::setMapColor(MapColor::map_red);
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "color_04_button_on_click\n";
}
void ChooseMapColorState::backButtonOnClick()
{
	GameController::getStateMachine()->changeState(new MenuState());
	std::cout << "back button clicked\n";
}
//void ChooseMapColorState::play_ButtonOnClick()
//{
//	GameController::getStateMachine()->changeState(new PlayState());
//	std::cout << "Play button clicked\n";
//}