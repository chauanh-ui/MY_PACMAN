#pragma once
#pragma once
#include"GameState.h"
#include "Button.h"

class HelpState : public GameState {
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
	LTexture helpTexture;
	static const int numberOfGhost = 4;

	
	LTexture ghosts[numberOfGhost];


	Button* backButton;
	Button* previousButton;
	Button* nextButton;


	static void backButtonOnClick();
	static void previousButtonOnClick();
	static void nextButtonOnClick();

};