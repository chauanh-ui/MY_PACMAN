#pragma once
#include "GameState.h"
#include <vector>
class GameStateMachine
{
public:

	// add a state without removing the previous state
	void pushState(GameState* pState);

	//  remove the previous state before adding another
	void changeState(GameState* pState);

	// will remove whichever state is currently being used without adding another
	void popState();

	void update(); // call update function of each state

	void handleEvent(SDL_Event& event);

	void render(); // call render function of each state
private:
	std::vector<GameState*> m_gameStates;
};
