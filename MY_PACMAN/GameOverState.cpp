//#include "MenuState.h"
//#include "SettingState.h"
//#include "GameController.h"
//#include <iostream>
//#include "PlayState.h"
//#include "GameOverState.h"
//const std::string GameOverState::s_menuID = "Game Over";
//
//void GameOverState::update()
//{
//
//	//chooseMapColorButton->update();
//	playAgainButton->update();
//	backToMenuButton->update();
//	
//}
//void GameOverState::render()
//{
//
//	gameOverTexture.render(-OffsetX, -OffsetY);
//	playAgainButton->draw();
//	backToMenuButton->draw();
//}
//
//void GameOverState::handleEvent(SDL_Event& event) {
//	//chooseMapColorButton->handleEvents(event);
//	playAgainButton->handleEvents(event);
//	backToMenuButton->handleEvents(event);
//
//}
//
//// tao va load anh va load button
//// goi ham khoi tao cua button
//bool GameOverState::onEnter()
//{
//	gameOverTexture.loadFromFile("Textures/GameOver.png");
//
//	playAgainButton = new Button("Textures/Button/playAgainButton.png", 171, 272, playAgainButtonOnClick);
//	backToMenuButton = new Button("Textures/Button/backToMenuButton.png", 351, 272, backToMenuButtonOnClick);
//	return true;
//}
//
//// clean kieu goi ham huy
//bool GameOverState::onExit()
//{
//
//	return true;
//}
//
//void GameOverState::playAgainButtonOnClick()
//{
//	GameController::getStateMachine()->changeState(new PlayState());
//}
//
//void GameOverState::backToMenuButtonOnClick()
//{
//	GameController::getStateMachine()->changeState(new MenuState());
//}
//
