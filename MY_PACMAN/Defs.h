#pragma once
#ifndef DEFS_H
#define DEFS_H
#include<iostream>

// Defs is used to define global const value to avoid "magic numbers"
// Using ALL-CAP words

// window const
const int WINDOW_WIDTH = 888;
const int WINDOW_HEIGHT = 672;
const std::string WINDOW_TITLE = "PACMAN GAME";

// map image const
const std::string IMAGE_MAP_PATH = "";
const int IMAGE_WIDTH = 0;
const int IMAGE_HEIGHT = 0;

enum class GameState {
	Intro,
	Play,
	Quit
};


#endif DEFS_H
