#pragma once
#ifndef DEFS_H
#define DEFS_H
#include<iostream>

#include <SDL.h>

// Defs is used to define global const value to avoid "magic numbers"
// Using ALL-CAP words

// window const
const int WINDOW_WIDTH = 672 / 2;
const int WINDOW_HEIGHT = 888 / 2;
const std::string WINDOW_TITLE = "PACMAN GAME";

// map image const
#define IMAGE_MAP_PATH "Images//Map24.png"
const int IMAGE_WIDTH = 0;
const int IMAGE_HEIGHT = 0;
const SDL_Rect IMAGE_MAP_SRC = { 0, 0, 672, 888 };
const SDL_Rect IMAGE_MAP_DST = { 0, 0, 672 / 2, 888 / 2};

enum class GameState {
	Intro,
	Play,
	Quit
};


#endif DEFS_H
