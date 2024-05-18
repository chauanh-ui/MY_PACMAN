#pragma once
#include"GameState.h"
#include "Button.h"

class ChooseMapColorState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual void handleEvent(SDL_Event& event);
	virtual std::string getStateID() const { return s_menuID; }
private:
	static const std::string s_menuID;
	//std::vector<Button*> menuButtons;
	LTexture chooseMapColorTexture;
	Button* blue_button;
	Button* green_button;
	Button* light_blue_button;
	Button* red_button;

	//Button* play_Button;


	Button* backButton;

	/*Button* playExtraButton;
	Button* helpButton;*/

	//Button* chooseMapThemeButton;

	// call back functions for menu items
	static void blue_button_on_click();
	static void green_button_on_click();
	static void light_blue_button_on_click();
	static void red_button_on_click();

	//static void play_ButtonOnClick();

	static void backButtonOnClick();
	
	//static void chooseMapThemeButtonOnClick();
};