#pragma once
#include<string>
#include "Common.h"
#include "Globals.h"
#include "Texture.h"
#include "Timer.h"
#include "Position.h"
#include "Entity.h"
#include "Pac.h"
#include "Ghost.h"
#include "Blinky.h"
#include "Inky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Fruit.h"
#include "Board.h"
#include "Sound.h"
#include "Game.h"
class GameState
{
public:
	virtual void handleEvent(SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};
