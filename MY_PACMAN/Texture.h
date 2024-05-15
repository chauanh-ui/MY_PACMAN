#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Common.h"
#include "Globals.h"

//class Texture
//{
//	SDL_Texture* texture = nullptr;
//	SDL_Rect src; // phan clip anh
//	SDL_Rect dst; // phan anh render len man hinh
//	double angle;
//	//SDL_Point center;
//
//public:
//	//Texture(const std::string imagePath, const SDL_Rect& _src, const SDL_Rect& _dst, SDL_Renderer* renderer);
//	Texture(std::string imagePath, SDL_Renderer* renderer);
//	~Texture();
//	/*void loadFromFile(const std::string imagePath, SDL_Renderer* renderer) {
//		texture = loadImage(imagePath, renderer);
//	}*/
//
//	void setDst(const SDL_Rect& _dst) {
//		dst = _dst;
//	}
//	void setSrc(const SDL_Rect& _src) {
//		src = _src;
//	}
//	void setAngle(double _angle) {
//		angle = _angle;
//	}
//
//	void render(SDL_Renderer* renderer, double angle = 0);
//
//	void setColor(SDL_Color color); 
//};
class LTexture{
	public:
		LTexture();
		~LTexture();
		bool loadFromFile(std::string path);
		bool loadFromRenderedText(std::string textureText, SDL_Color textColor, bool IsLittle = 0);
		void free();
		void setColor(uint8_t red, uint8_t green, uint8_t blue);
		void setBlendMode(SDL_BlendMode blending);
		void setAlpha(uint8_t alpha);
		void render(short x = 0, short y = 0, unsigned char facing = 0, SDL_Rect* clip = NULL);
		int getWidth();
		int getHeight();
	private:
		SDL_Texture* mTexture;
		unsigned short mWidth;
		unsigned short mHeight;
};


#endif TEXTURE_H
