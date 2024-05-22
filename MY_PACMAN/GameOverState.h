//#pragma once
//#include"GameState.h"
//#include "Button.h"
//
//class GameOverState : public GameState {
//public:
//	virtual void update();
//	virtual void render();
//	virtual bool onEnter();
//	virtual bool onExit();
//	virtual void handleEvent(SDL_Event& event);
//	virtual std::string getStateID() const { return s_menuID; }
//private:
//	static const std::string s_menuID;
//
//	LTexture gameOverTexture;
//	Button* playAgainButton;
//	Button* backToMenuButton;
//
//	static void playAgainButtonOnClick();
//
//	static void backToMenuButtonOnClick();
//
//
//};