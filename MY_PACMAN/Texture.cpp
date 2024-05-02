#include "Texture.h"

//Texture::Texture(const std::string imagePath,const SDL_Rect& _src, const SDL_Rect& _dst, SDL_Renderer* renderer) {
//	texture = loadImage(imagePath, renderer);
//	src = _src;
//	dst = _dst;
//}

Texture::Texture(std::string imagePath, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
}


Texture:: ~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
}

void Texture::render(SDL_Renderer* renderer, double angle, SDL_RendererFlip flip) {
	SDL_Point center;
	center.x = dst.x + dst.w / 2;
	center.y = dst.y + dst.y / 2;
	SDL_RenderCopyEx(renderer, texture, &src, &dst, angle, &center, flip);
}




void Texture::setColor(SDL_Color color) {
	SDL_SetTextureColorMod(texture, color.r, color.g, color.b);
}

