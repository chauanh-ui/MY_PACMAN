#include "Pacman.h"
#include "Entity.h"
#include <vector>

Pacman::Pacman(SDL_Renderer* gRenderer, ) {
	animation = new Animation(PACMAN_LEFT_PATH,PACMAN_HORI , PACMAN_IMAGE_CONTAINER, gRenderer);
}