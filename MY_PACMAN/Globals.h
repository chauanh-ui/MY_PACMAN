#pragma once
#ifndef GLOBALS_H

#define GLOBALS_H
#include "Common.h"
const unsigned char BoardWidth = 28;
const unsigned char BoardHeight = 36;
const unsigned char BlockSize32 = 32;
//const unsigned char BlockSize24 = 24;
const unsigned char BlockSize24 = 16;
const unsigned short OffsetX = 50;
const unsigned short OffsetY = 50;
const unsigned short WindowWidth = OffsetX + BoardWidth * BlockSize24 + OffsetX; // 548
const unsigned short WindowHeight = OffsetY + BoardHeight * BlockSize24 + OffsetY; // 676

const std::string CharBoard =
"                            "
"                            "
"                            "
"############################"
"#............##............#"
"#.####.#####.##.#####.####.#"
"#o####.#####.##.#####.####o#"
"#.####.#####.##.#####.####.#"
"#..........................#"
"#.####.##.########.##.####.#"
"#.####.##.########.##.####.#"
"#......##....##....##......#"
"######.##### ## #####.######"
"     #.##### ## #####.#     "
"     #.##    1     ##.#     "
"     #.## ###==### ##.#     "
"######.## #      # ##.######"
"      .   #2 3 4 #   .      "
"######.## #      # ##.######"
"     #.## ######## ##.#     "
"     #.##          ##.#     "
"     #.## ######## ##.#     "
"######.## ######## ##.######"
"#............##............#"
"#.####.#####.##.#####.####.#"
"#.####.#####.##.#####.####.#"
"#o..##.......0 .......##..o#"
"###.##.##.########.##.##.###"
"###.##.##.########.##.##.###"
"#......##....##....##......#"
"#.##########.##.##########.#"
"#.##########.##.##########.#"
"#..........................#"
"############################"
"                            "
"                            ";

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
	ePacMan, eBlinky, eInky, ePinky, eClyde, Noone
};


enum class PlayMode {
	Play, PlayExtra
};
enum class MapColor {
	map_blue, map_green, map_pink, map_purple
};

enum class MapTheme {
	Dark, Light
};
enum class PacType {
	Original, Boy, Mom
};



//enum class GameState {
//	Intro,
//	Setting,
//	Play, // setting chinh am thanh
//	ChooseMap,
//	ChooseChar,
//	PlayExtra,
//	Quit
//};

void InitializeSDL();
void CloseSDL();

void InitFrames(const unsigned char TotalFrames, SDL_Rect SpriteClips[], unsigned char CurrentBlockSize = BlockSize32);

#endif GLOBALS_H