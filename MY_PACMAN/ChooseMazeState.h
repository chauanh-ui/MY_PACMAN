#pragma once
#pragma once
#include"GameState.h"
#include "Button.h"

class ChooseMazeState : public GameState {
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
	LTexture chooseMazeTexture;

	// use for loop to load
	LTexture mazePreview[numberOfBoards];

	Button* previous_button; // decrease board (board: 0 -> numberOfMazes)
	Button* next_button; // increase board

	Button* playButton;

	static void previous_button_on_click();

	static void next_button_on_click();

	static void playButtonOnClick();

};