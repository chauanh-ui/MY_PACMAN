#pragma once
#include "GameState.h"
class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
private:
	static const std::string s_playID;
	Game mGame;
	Timer GameTimer;
	//SDL_Event event;
	bool quit = false;
	unsigned short StartTicks = 4500;
	std::vector<unsigned char> mover;
	double IterationStart;
};