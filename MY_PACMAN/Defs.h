﻿#pragma once
#ifndef DEFS_H
#define DEFS_H
#include<iostream>

#include <SDL.h>
#include <vector>

// Defs is used to define global const value to avoid "magic numbers"
// Using ALL-CAP words
const int BLOCKSIZE16 = 16; // dimension of 1 single block
const int BLOCKSIZE32 = 32;
const int TOTAL_BLOCK_X = 28;
const int TOTAL_BLOCK_Y = 36;
const int TOTAL_BLOCK = TOTAL_BLOCK_X * TOTAL_BLOCK_Y;

const int OFFSET_Y_TOP = 0;
const int OFFSET_Y_BOTTOM = 0;
// window const
const int WINDOW_WIDTH = BLOCKSIZE16 * TOTAL_BLOCK_X;
const int WINDOW_HEIGHT = BLOCKSIZE16 * TOTAL_BLOCK_Y;
const std::string WINDOW_TITLE = "PACMAN GAME";

// map image const
#define IMAGE_MAP_PATH "Images//Map24.png"
const int IMAGE_MAP_WIDTH = 672; // 28 * 24
const int IMAGE_MAP_HEIGHT = 888; // 37 * 24
const SDL_Rect IMAGE_MAP_SRC = { 0, 0, 28 * 24, 36 * 24 }; // lấy full map
const SDL_Rect IMAGE_MAP_DST = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
const std::string MAP_FILE_TXT = "Images//Map.txt";

const std::string charMap = // map dạng char
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

extern int board[TOTAL_BLOCK_Y][TOTAL_BLOCK_X];

//void loadNumericMap() {
//	for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
//		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
//			switch (charMap[i * TOTAL_BLOCK_X + j]) {
//			case '#':
//				numericMap[i][j] = WALL;
//				break;
//			case '=':
//				numericMap[i][j] = DOOR;
//				break;
//			case '.':
//				numericMap[i][j] = PELLET;
//				break;
//			case 'o':
//				numericMap[i][j] = ENERGIZER;
//				break;
//			default:
//				numericMap[i][j] = NOTHING;
//				break;
//			}
//		}
//	}
//	/*for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
//		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
//			std::cout << numericMap[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}*/
//}


//blocktype
const int WALL = 0, DOOR = 1, PELLET = 2, ENERGIZER = 3, NOTHING = 4;
const int PELLET_SCORE = 10;
const int ENERGIZER_SCORE = 50;
const int MAX_FRAMES = 10;

// map color
const SDL_Color GREEN = { 77, 196, 124 };
const SDL_Color BLUE = { 103, 178, 224 };
const SDL_Color PINK = { 230, 126, 186 };
const SDL_Color PURPLE = { 180, 126, 230 };

// entityType
const int PACMAN = 0, BLINKY = 1, INKY = 2, PINKY = 3, CLYDE = 4, NO_ONE = 5;


// direction
const int DIRECTION_UP = 0, DIRECTION_DOWN = 1, DIRECTION_LEFT = 2, DIRECTION_RIGHT = 3;

const int LIVING_PAC_FRAMES = 3;
const int DEATH_PAC_FRAMES = 10;
const int GHOST_BODY_FRAMES = 6;
const int GHOST_EYE_FRAMES = 5;
const int FRUIT_FRAMES = 8;


//Pacman
const std::string PACMAN_IMAGE_PATH = "Images//PacMan32.png";
const SDL_Rect PACMAN_IMAGE_SRC = { 0, 0, 32, 32 };
const SDL_Rect PACMAN_START_POS = {13 * BLOCKSIZE16 + BLOCKSIZE16 / 2, 19 * BLOCKSIZE16 + BLOCKSIZE16 / 2,
2 * BLOCKSIZE16, 2 * BLOCKSIZE16};

const std::vector<SDL_Rect> PACMAN_HORIZONTAL_CLIPS = {
	{0,0,32,32},
	{32,0,32,32},
	{64,0,32,32}
};

const std::vector<SDL_Rect> PACMAN_VERTICAL_CLIPS = {
	{0, 0, 32, 32},
	{0, 32, 32, 32},
	{0, 64, 32, 32}
};
const std::string PACMAN_RIGHT_PATH = "Images//Pacman32.png";



// enum class
enum class GameState {
	Intro,
	Play,
	Quit
};


#endif DEFS_H
