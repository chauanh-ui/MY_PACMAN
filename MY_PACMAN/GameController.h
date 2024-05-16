#pragma once
#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H
#include "GameStateMachine.h"
//#include "Common.h"
//#include "Globals.h"
//#include "Texture.h"
//#include "Timer.h"
//#include "Position.h"
//#include "Entity.h"
//#include "Pac.h"
//#include "Ghost.h"
//#include "Blinky.h"
//#include "Inky.h"
//#include "Pinky.h"
//#include "Clyde.h"
//#include "Fruit.h"
//#include "Board.h"
//#include "Sound.h"
//#include "Game.h"
////
////#include "Common.h"
////#include "Defs.h"
////#include "Map.h"
////#include "Entity.h"
////#include "Pacman.h"
////#include "Inky.h"
////#include "Menu.h"
//// 
////class GameObject {
////	SDL_Window* gWindow;
////	SDL_Renderer* gRenderer;
////	SDL_Event e;
////	Menu* menu;
////	Texture* map;
////	SDL_Color mapColor;
////
////	Texture* smallDot;
////	Texture* bigDot;
////	Texture* testDot;
////	Inky* inky;
////	//Pacman* simplePacman;
////	Pacman* simplePacman;
////
////public:
////	GameState gameState;
////	//void initialize(); // lan luot gap cac ham khoi tao cua may con kia
////	//void renderGame(); // goi lam render cua cac con kia
////	//void running(); // vong while // game loop
////	//~GameObject();
////	void initialize(); // khoi tao các nhân vật, hình ảnh,... trong game
////	void renderGame(); // vẽ game lên màn hình
////	void running(); // lần lượt gọi intro, play, ..
////	void introGame();
////	void play();
////	//void gameOver();
////	~GameObject();
////};
//class GameController {
//	GameState gameState;
//	void initialize();
//
//};
	//GameStateMachine* m_pGameStateMachine;
class GameController {
	static GameStateMachine* m_pGameStateMachine;
	SDL_Event g_event;
	/*Game mGame;
	Timer GameTimer;
	SDL_Event event;
	bool quit = false;
	unsigned short StartTicks = 4500;
	std::vector<unsigned char> mover;*/
	double IterationStart;
	bool quit;

public:

	//void initialize();
	//void handleInput();
	~GameController();

	static GameStateMachine* getStateMachine();
	void init();
	void handleEvents();
	void update(); // {m_pGameStateMachine->update()}
	void render(); // {sdl_renderclear  m_pGameStateMachine->render()  sdl_rendererpresent}
	void running(); 
	void gameDelay();

	//void close();
};






#endif GAMEOBJECT_H