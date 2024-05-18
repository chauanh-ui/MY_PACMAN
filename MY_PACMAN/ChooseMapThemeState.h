#pragma once
#pragma once
#include"GameState.h"
#include "Button.h"

class ChooseMapThemeState : public GameState {
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
	LTexture chooseMapThemeTexture;
	Button* water_button;
	Button* sand_button;
	Button* wood_button;
	Button* leaf_button;

	//Button* play_Button;


	Button* backButton;

	/*Button* playExtraButton;
	Button* helpButton;*/

	//Button* chooseMapThemeButton;

	// call back functions for menu items
	static void water_button_on_click();
	static void sand_button_on_click();
	static void wood_button_on_click();
	static void leaf_button_on_click();

	//static void play_ButtonOnClick();

	static void backButtonOnClick();

	//static void chooseMapThemeButtonOnClick();
};