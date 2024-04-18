#include "Texture.h"

Texture:: Texture(std::string imagePath,const SDL_Rect& _src, const SDL_Rect& _dst, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
	src = _src;
	dst = _dst;
}

Texture:: ~Texture() {
	texture = NULL;
}

void Texture::setSrc(SDL_Rect& _src) {
	src = _src;
}
void Texture::setDst(SDL_Rect& _dst) {
	dst = _dst;
}
void Texture::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Texture::setColor(SDL_Color color) {
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

