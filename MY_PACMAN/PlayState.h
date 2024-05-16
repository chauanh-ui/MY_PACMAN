#pragma once
#include "GameState.h"
#include "Globals.h"
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual void handleEvent(SDL_Event& event);
	virtual std::string getStateID() const { return s_playID; }
private:
	static const std::string s_playID;
	Game mGame;
	Timer GameTimer;
	//SDL_Event event;
	unsigned short StartTicks = 4500;
	std::vector<unsigned char> mover;
	bool processSuccess;
};