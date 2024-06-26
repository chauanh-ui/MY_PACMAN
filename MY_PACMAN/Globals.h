#pragma once
#ifndef GLOBALS_H

#define GLOBALS_H
#include "Common.h"
const unsigned char BoardWidth = 28;
const unsigned char BoardHeight = 36;
const unsigned char BlockSize32 = 32;
//const unsigned char BlockSize24 = 24;
const unsigned char BlockSize24 = 16;
const unsigned short OffsetX = 100;
const unsigned short OffsetY = 50;
const unsigned short WindowWidth = OffsetX + BoardWidth * BlockSize24 + OffsetX; // 548
const unsigned short WindowHeight = OffsetY + BoardHeight * BlockSize24 + OffsetY; // 776

const int numberOfBoards = 5;

extern std::string CharBoard;

// index of charboard string in extraBoards; // update in choose maze state
extern int board;

extern bool isPlayExtra;

extern bool isGhostAdded;

extern std::string extraBoards[numberOfBoards];

// update in choose map theme state
extern int mazeTexture;

extern int currentGhost;

enum blockTexture {
	water, sand, wood, leaf
};


const unsigned char LivingPacFrames = 3;
const unsigned char DeathPacFrames = 10;
const unsigned char GhostBodyFrames = 6;
const unsigned char GhostEyeFrames = 5;
const unsigned char FruitFrames = 8;


const unsigned short ScoreTable[FruitFrames] = { 100, 300, 500, 700, 1000, 2000, 3000, 5000 };

const SDL_Color Black = { 0x00, 0x00, 0x00 };
const SDL_Color White = { 0xff, 0xff, 0xff };
const SDL_Color Yellow = { 0xff, 0xff, 0x00 };
const SDL_Color Red = { 0xff, 0x00, 0x00 };
const SDL_Color Cyan = { 0x00, 192, 0xff };
const SDL_Color Pink = { 0xff, 192, 203 };
const SDL_Color Orange = { 0xff, 128, 0x00 };
const SDL_Color Green = { 3, 252, 32 }; // #03fc20

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Rect* CurrentClip;
extern TTF_Font* Font;
extern TTF_Font* LittleFont;


//extern SDL_Event event;
enum BlockType {
	Wall, Door, Pellet, Energizer, Nothing
};

enum Direction {
	Right, Up, Left, Down, Nowhere
};
enum EntityType {
	ePacMan, eBlinky, eInky, ePinky, eClyde, addedGhost
};


enum class MapColor {
	map_blue, map_green, map_light_blue, map_red
};



void InitializeSDL();
void CloseSDL();

void InitFrames(const unsigned char TotalFrames, SDL_Rect SpriteClips[], unsigned char CurrentBlockSize = BlockSize32);

//std::string readTextFileToString(const std::string& filename);

std::string readStringFromCSVFile(const std::string& filePath, int numRows, int numsPerRow);


void loadExtraBoards();

#endif GLOBALS_H