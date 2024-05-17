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
	Button* color_01_button;
	Button* color_02_button;
	Button* color_03_button;
	Button* color_04_button;

	Button* play_Button;


	Button* backButton;

	/*Button* playExtraButton;
	Button* helpButton;*/

	//Button* chooseMapThemeButton;

	// call back functions for menu items
	static void color_01_button_on_click();
	static void color_02_button_on_click();
	static void color_03_button_on_click();
	static void color_04_button_on_click();

	static void play_ButtonOnClick();

	static void backButtonOnClick();
	
	//static void chooseMapThemeButtonOnClick();
};