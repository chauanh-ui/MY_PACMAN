#pragma once
#include"GameState.h"
#include "Button.h"

class MenuState : public GameState {
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
	LTexture menuTexture;
	Button* playButton;
	Button* playExtraButton;
	Button* helpButton;
	//Button* settingButton;

	// call back functions for menu items
	static void playButtonOnClick();
	static void playExtraButtonOnClick();
	static void helpButtonOnClick();
	//static void settingButtonOnClick();

};