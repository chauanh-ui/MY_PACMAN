#pragma once
#ifndef COMMON_H
#define COMMON_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <cmath>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#endif COMMON_H



//#ifndef COMMON_H
//#define COMMON_H
//
//#include<iostream>
//#include<string>
//#include<SDL.h>
//#include<SDL_image.h>
//#include<SDL_mixer.h>
//#include<SDL_ttf.h>
//#include "Defs.h"
//
//// Common.h declares global functions used through out the whole game
//
//TTF_Font* loadFont(std::string font_path);
//SDL_Texture* loadText(std::string text, std::string font_path, SDL_Renderer* renderer);
//SDL_Texture* loadImage(const std::string path, SDL_Renderer* renderer);
//
//Mix_Chunk* loadAudio(std::string audioPath);
//void playAudio(Mix_Chunk* sound);
//
//bool checkCollision(const SDL_Rect a, const SDL_Rect b);
////bool checkCollisionCircle(const SDL_Point center, const SDL_Rect a);
//
//Mix_Music* loadMusic(const char* path);
//void playMusic(Mix_Music* gMusic);
//
//void logSDLError(std::ostream& os, const std::string& msg, bool fatal);
//void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
//void waitUntilKeyPressed();
//void InitFrames(int TotalFrames, SDL_Rect SpriteClips[], int CurrentBlockSize = 2 * BLOCKSIZE16);
//void generateNumericMap();
//
//
//#endif COMMON_H