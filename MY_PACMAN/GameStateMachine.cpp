#include "GameStateMachine.h"
#include <iostream>

void GameStateMachine::pushState(GameState* pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

//void GameStateMachine::changeState(GameState* pState)
//{
//	if (!m_gameStates.empty())
//	{
//		if (m_gameStates.back()->getStateID() == pState->getStateID())
//		{
//			return; // do nothing
//		}
//		if (m_gameStates.back()->onExit())
//		{
//			std::cout << "delete " << m_gameStates.back()->getStateID() << std::endl;
//			delete m_gameStates.back();
//			m_gameStates.pop_back();
//		}
//	}
//	m_gameStates.push_back(pState);
//	// initialise it
//	m_gameStates.back()->onEnter();
//}



void GameStateMachine::changeState(GameState* pState)
{
	if (!m_gameStates.empty())
	{
		/*if (m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return;
		}*/
		if (m_gameStates.back()->onExit())
		{
			//delete m_gameStates.back();
			m_gameStates.push_back(pState);
			auto it = m_gameStates.end() - 2;
			m_gameStates.erase(it);
			//m_gameStates.pop_back();
		}
	}
	else
		m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}
void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::handleEvent(SDL_Event& event) {
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->handleEvent(event);
	}
}

GameStateMachine::~GameStateMachine() {
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->onExit();
	}
}

std::string GameStateMachine::getCurrentStateId() {
	if (!m_gameStates.empty())
	{
		return m_gameStates.back()->getStateID();
	}
	return "No State";
}