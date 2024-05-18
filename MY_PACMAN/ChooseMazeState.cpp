#include "MenuState.h"
#include "ChooseMazeState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
const std::string ChooseMazeState::s_menuID = "CHOOSE_MAZE";

void ChooseMazeState::update()
{

	std::cout << "cmc update\n";
	previous_button->update();
	next_button->update();
	playButton->update();
}
void ChooseMazeState::render()
{
	chooseMazeTexture.render(-OffsetX, -OffsetY);
	previous_button->draw();
	// render mazePreview

	std::cout << "board: " << board << std::endl;
	mazePreview[board].render(50 - OffsetX, 261 - OffsetY);


	
	next_button->draw();
	playButton->draw();

}

void ChooseMazeState::handleEvent(SDL_Event& event) {
	previous_button->handleEvents(event);
	next_button->handleEvents(event);
	playButton->handleEvents(event);

}

// tao va load anh va load button
// goi ham khoi tao cua button
bool ChooseMazeState::onEnter()
{
	std::cout << "entering choose map color state\n";
	chooseMazeTexture.loadFromFile("Textures/ChooseMaze.png");

	// vong for load mazePreview
	for (int i = 0; i < numberOfBoards; i++) {
		std::string path = "Maps/map_" + std::to_string(i) + ".png";
		mazePreview[i].loadFromFile(path);
	}

	previous_button = new Button("Textures/Button/previous_button.png", 352, 387, previous_button_on_click);
	next_button = new Button("Textures/Button/next_button.png", 517, 443, next_button_on_click);
	playButton = new Button("Textures/Button/playButton.png", 385, 314, playButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool ChooseMazeState::onExit()
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

void ChooseMazeState::previous_button_on_click()
{
	board--;
	if (board < 0) {
		board = 0;
	}
	std::cout << "previous_button_on_click\n";
}
void ChooseMazeState::next_button_on_click()
{
	board++;
	if (board > numberOfBoards - 1) {
		board = 0;
	}
	std::cout << "next_button_on_click\n";
}

void ChooseMazeState::playButtonOnClick()
{
	GameController::getStateMachine()->changeState(new PlayState());
	std::cout << "Play button clicked\n";
}