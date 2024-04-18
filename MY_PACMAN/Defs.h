﻿#pragma once
#ifndef DEFS_H
#define DEFS_H
#include<iostream>

#include <SDL.h>

// Defs is used to define global const value to avoid "magic numbers"
// Using ALL-CAP words
const int BLOCKSIZE16 = 16; // dimension of 1 single block
const int TOTAL_BLOCK_X = 28;
const int TOTAL_BLOCK_Y = 36;
const int TOTAL_BLOCK = TOTAL_BLOCK_X * TOTAL_BLOCK_Y;

const int OFFSET_Y_TOP = 0;
const int OFFSET_Y_BOTTOM = 0;
// window const
const int WINDOW_WIDTH = BLOCKSIZE16 * TOTAL_BLOCK_X;
const int WINDOW_HEIGHT = OFFSET_Y_TOP + BLOCKSIZE16 * TOTAL_BLOCK_Y + OFFSET_Y_BOTTOM;
const std::string WINDOW_TITLE = "PACMAN GAME";

// map image const
#define IMAGE_MAP_PATH "Images//Map24.png"
const int IMAGE_MAP_WIDTH = 672; // 28 * 24
const int IMAGE_MAP_HEIGHT = 888; // 37 * 24
const SDL_Rect IMAGE_MAP_SRC = { 0, 0, 672, 888 }; // lấy full ảnh
const SDL_Rect IMAGE_MAP_DST = { 0, OFFSET_Y_TOP, WINDOW_WIDTH, BLOCKSIZE16 * TOTAL_BLOCK_Y };
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

//blocktype
const unsigned char WALL = '0', DOOR = '1', PELLET = '2', ENERGIZER = '3', NOTHING = '4';

// map color
const SDL_Color GREEN = { 77, 196, 124 };
const SDL_Color BLUE = { 103, 178, 224 };
const SDL_Color PINK = { 230, 126, 186 };
const SDL_Color PURPLE = { 180, 126, 230 };

// entityType
const int PACMAN = 0, BLINKY = 1, INKY = 2, PINKY = 3, CLYDE = 4, NO_ONE = 5;


// direction
const int DIRECTION_UP = 0, DIRECTION_DOWN = 1, DIRECTION_LEFT = 2, DIRECTION_RIGHT = 3;

//Pacman
const std::string PACMAN_IMAGE_PATH = "Images//Lives32.png";
const SDL_Rect PACMAN_IMAGE_SRC = { 0, 0, 32, 32 };
const SDL_Rect PACMAN_IMAGE_CONTAINER = {13 * BLOCKSIZE16, 19 * BLOCKSIZE16, 
										2 * BLOCKSIZE16, 2 * BLOCKSIZE16};

// enum class
enum class GameState {
	Intro,
	Play,
	Quit
};


#endif DEFS_H
