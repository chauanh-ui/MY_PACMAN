#pragma once
#include"GameState.h"
#include "Button.h"

class SettingState : public GameState {
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
	LTexture settingTexture;
	//Button* chooseMapColorButton;
	Button* backButton;

	/*Button* playExtraButton;
	Button* helpButton;*/

	//Button* chooseMapThemeButton;

	// call back functions for menu items
	//static void chooseMapColorButtonOnClick();

	static void backButtonOnClick();
	
	//static void chooseMapThemeButtonOnClick();
};