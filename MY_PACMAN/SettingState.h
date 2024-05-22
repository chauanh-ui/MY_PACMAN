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

	LTexture settingTexture;

	LTexture addedGhostTexture;
	LTexture greendyTexture;

	Button* addButton; // isGhostAdded = true

	Button* minusButton; // isGhostAdd = false

	Button* okButton; // change to menu state // pop state

	
	static void minusButtonOnClick();

	static void addButtonOnClick();

	static void okButtonOnClick();
	
};