//#include "MenuState.h"
//#include "SettingState.h"
//#include "GameController.h"
//#include <iostream>
//#include "PlayState.h"
//const std::string SettingState::s_menuID = "SETTING";
//
//void SettingState::update()
//{
//	
//	std::cout << "setting update\n";
//	//chooseMapColorButton->update();
//	backButton->update();
//	
//}
//void SettingState::render()
//{
//	// nothing for now
//	/*for (int i = 0; i < menuButtons.size(); i++)
//	{
//		menuButtons[i]->draw();
//	}*/
//	std::cout << "setting render\n";
//	settingTexture.render();
//	//chooseMapColorButton->draw();
//	backButton->draw();
//}
//
//void SettingState::handleEvent(SDL_Event& event) {
//	//chooseMapColorButton->handleEvents(event);
//	backButton->handleEvents(event);
//
//}
//
//// tao va load anh va load button
//// goi ham khoi tao cua button
//bool SettingState::onEnter()
//{
//	std::cout << "entering setting\n";
//	settingTexture.loadFromFile("Textures/Menu.png");
//	//chooseMapColorButton = new Button("Textures/Button/chooseMapColorButton.png", 200, 200, chooseMapColorButtonOnClick);
//
//	/*playExtraButton = new Button("Textures//Button//playExtraButton.png", 200, 300, playExtraButtonOnClick);
//	helpButton = new Button("Textures//Button//helpButton.png", 200, 400, helpButtonOnClick);*/
//	backButton = new Button("Textures/Button/backButton.png", 200, 500, backButtonOnClick);
//	return true;
//}
//
//// clean kieu goi ham huy
//bool SettingState::onExit()
//{
//	//delete menuTexture;
//	//delete chooseMapColorButton;
//	/*delete playExtraButton;
//	delete helpButton;*/
//	delete backButton;
//	backButton = nullptr;
//	std::cout << "exiting setting\n";
//	return true;
//}
//
////void SettingState::chooseMapColorButtonOnClick()
////{
////	//GameController::getStateMachine()->pushState(new chooseMapColorState());
////	std::cout << "Play button clicked\n";
////}
////void MenuState::playExtraButtonOnClick()
////{
////	std::cout << "Exit button clicked\n";
////}
////void MenuState::helpButtonOnClick()
////{
////	std::cout << "Help button clicked\n";
////}
//void SettingState::backButtonOnClick()
//{
//	GameController::getStateMachine()->changeState(new MenuState());
//	std::cout << "back button clicked\n";
//}