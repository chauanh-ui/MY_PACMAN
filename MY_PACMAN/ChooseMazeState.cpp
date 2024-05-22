#include "MenuState.h"
#include "ChooseMazeState.h"
#include "GameController.h"
#include <iostream>
#include "PlayState.h"
#include "ChooseMapThemeState.h"
const std::string ChooseMazeState::s_menuID = "CHOOSE_MAZE";

void ChooseMazeState::update()
{

	previous_button->update();
	next_button->update();
	playButton->update();
}
void ChooseMazeState::render()
{
	chooseMazeTexture.render(-OffsetX, -OffsetY);
	previous_button->draw();
	// render mazePreview

	mazePreview[board].render(47 - OffsetX, 145 - OffsetY);


	
	next_button->draw();
	playButton->draw();

}

void ChooseMazeState::handleEvent(SDL_Event& event) {
	previous_button->handleEvents(event);
	next_button->handleEvents(event);
	playButton->handleEvents(event);
	if (event.key.keysym.sym == SDLK_ESCAPE) {
		GameController::getStateMachine()->changeState(new ChooseMapThemeState());
	}

}

// tao va load anh va load button
// goi ham khoi tao cua button
bool ChooseMazeState::onEnter()
{
	chooseMazeTexture.loadFromFile("Textures/ChooseMaze.png");

	// vong for load mazePreview
	for (int i = 0; i < numberOfBoards; i++) {
		std::string path = "Maps/" + std::to_string(mazeTexture + 1)+ "/map_" + std::to_string(i + 1) + ".png";
		mazePreview[i].loadFromFile(path);
	}

	previous_button = new Button("Textures/Button/previous_button.png", 426, 319, previous_button_on_click);
	next_button = new Button("Textures/Button/next_button.png", 524, 319, next_button_on_click);
	playButton = new Button("Textures/Button/playButton.png", 454, 259, playButtonOnClick);
	return true;
}

// clean kieu goi ham huy
bool ChooseMazeState::onExit()
{
	
	return true;
}



void ChooseMazeState::previous_button_on_click()
{
	board--;
	if (board < 0) {
		board = 0;
	}
}
void ChooseMazeState::next_button_on_click()
{
	board++;
	if (board > numberOfBoards - 1) {
		board = 0;
	}
}

void ChooseMazeState::playButtonOnClick()
{
	GameController::getStateMachine()->changeState(new PlayState());
}