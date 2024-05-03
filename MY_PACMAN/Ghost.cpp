#include "Ghost.h"


Ghost::Ghost(SDL_Renderer* renderer) : Entity(GHOST, renderer) {
	currentEyesFrames = 0;
	facing = 0;
	speed = BLOCKSIZE16;
	entityTexture = new Texture(GHOST_IMAGE_PATH, renderer);
	eyesTexture = new Texture(EYES_IMAGE_PATH, renderer);
	setTotalFrames(GHOST_BODY_FRAMES);
	clips.resize(totalFrames);
	initFrames();
	initEyesFrames();
}

void Ghost::renderGhost(SDL_Renderer* renderer) {
	renderEntity(renderer);
	eyesTexture->setSrc(eyesClips[currentEyesFrames / GHOST_EYE_FRAMES]); // clips nay lay dau ra ??? -> cho vao hay gi
	eyesTexture->setDst(currentPos); //update thang khi goi ham move
	eyesTexture->render(renderer);
	SDL_Delay(20);
	tickEyesFrames();
}

void Ghost::moving() {
	;
}

Ghost::~Ghost() {
	delete eyesTexture;
}