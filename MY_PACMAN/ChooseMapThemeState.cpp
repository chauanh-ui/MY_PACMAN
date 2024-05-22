#include "MenuState.h"
#include "ChooseMapThemeState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
#include "ChooseMazeState.h"
const std::string ChooseMapThemeState::s_menuID = "CHOOSE_MAP_THEME";

void ChooseMapThemeState::update()
{

	water_button->update();
	sand_button->update();
	wood_button->update();
	leaf_button->update();
	//playButton->update();
	backButton->update();

}
void ChooseMapThemeState::render()
{
	// nothing for now
	/*for (int i = 0; i < menuButtons.size(); i++)
	{
		menuButtons[i]->draw();
	}*/
	chooseMapThemeTexture.render(-OffsetX, -OffsetY);
	water_button->draw();
	sand_button->draw();
	wood_button->draw();
	leaf_button->draw();
	//play_Button->draw();
	backButton->draw();
}

void ChooseMapThemeState::handleEvent(SDL_Event& event) {
	water_button->handleEvents(event);
	sand_button->handleEvents(event);
	wood_button->handleEvents(event);
	leaf_button->handleEvents(event);
	//play_Button->handleEvents(event);
	backButton->handleEvents(event);
	if (event.key.keysym.sym == SDLK_ESCAPE) {
		GameController::getStateMachine()->changeState(new MenuState());
	}
}

// tao va load anh va load button
// goi ham khoi tao cua button
bool ChooseMapThemeState::onEnter()
{
	chooseMapThemeTexture.loadFromFile("Textures/ChooseMapTheme.png");
	water_button = new Button("Textures/Button/water_button.png", 54, 200, water_button_on_click);
	sand_button = new Button("Textures/Button/sand_button.png", 339, 200, sand_button_on_click);
	wood_button = new Button("Textures/Button/wood_button.png", 54, 436, wood_button_on_click);
	leaf_button = new Button("Textures/Button/leaf_button.png", 339, 436, leaf_button_on_click);

	//play_Button = new Button("Textures/Button/playButton.png", 200, 100, play_ButtonOnClick);
	/*playExtraButton = new Button("Textures//Button//playExtraButton.png", 200, 300, playExtraButtonOnClick);
	helpButton = new Button("Textures//Button//helpButton.png", 200, 400, helpButtonOnClick);*/
	backButton = new Button("Textures/Button/backButton.png", 230, 672, backButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool ChooseMapThemeState::onExit()
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

void ChooseMapThemeState::water_button_on_click()
{
	mazeTexture = water;
	GameController::getStateMachine()->changeState(new ChooseMazeState());
}
void ChooseMapThemeState::sand_button_on_click()
{
	mazeTexture = sand;
	GameController::getStateMachine()->changeState(new ChooseMazeState());
}
void ChooseMapThemeState::wood_button_on_click()
{
	mazeTexture = wood;
	GameController::getStateMachine()->changeState(new ChooseMazeState());
}
void ChooseMapThemeState::leaf_button_on_click()
{
	mazeTexture = leaf;
	GameController::getStateMachine()->changeState(new ChooseMazeState());
}
void ChooseMapThemeState::backButtonOnClick()
{
	GameController::getStateMachine()->changeState(new ChooseMazeState());
}
