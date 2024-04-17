#include "Texture.h"

Texture:: Texture(std::string imagePath,const SDL_Rect& _src,const SDL_Rect& _dst, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
	src = _src;
	dst = _dst;
}

Texture:: ~Texture() {
	texture = NULL;
}
void Texture::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Texture::setColor(uint8_t red, uint8_t green, uint8_t blue) {
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

