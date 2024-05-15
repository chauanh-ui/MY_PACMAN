//#include "Animation.h"
//
//Animation::Animation(const std::string imagePath, const std::vector<SDL_Rect>& _clips, const SDL_Rect& _dst, SDL_Renderer* gRenderer) {
//	texture = loadImage(imagePath, gRenderer);
//	clips = _clips;
//	dst = _dst;
//}
//
//void Animation::renderAnimation(SDL_Renderer* renderer) {
//	SDL_RenderCopy(renderer, texture, getCurrentClip(), &dst);
//	SDL_Delay(20);
//	tick();
//}
//
//
//Animation::~Animation() {
//	if (texture != nullptr) {
//		SDL_DestroyTexture(texture);
//	}
//}