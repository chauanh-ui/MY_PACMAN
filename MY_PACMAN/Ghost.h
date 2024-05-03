#pragma once
#ifndef GHOST_H
#define GHOST_H

#include "Entity.h"
class Ghost : public Entity {
public:
	int currentEyesFrames = 0;
	bool shouldTurn[4] = { false, false, false, false };
	bool isFrighten = false;
	SDL_Color ghostColor;
	Texture* eyesTexture;
	int ghostType;
	std::vector<SDL_Rect> eyesClips;




	Ghost(SDL_Renderer* renderer);
	~Ghost();
	void moving();
	void setIsFrighten(bool _isPanEnergized) {
		isFrighten = _isPanEnergized;
	}
	void resetIsFrighten() {
		isFrighten = false;
	}

	void setColor(const SDL_Color& _ghostColor, bool isFrighten = false) {
		ghostColor = _ghostColor;
		if (isFrighten) {
			ghostColor = GHOST_FRIGHTEN_COLOR;
		}
	}

	void setTextureColor() {
		entityTexture->setColor(ghostColor);
	}

	void updateShouldTurn();
	void resetShouldTurn() {
		shouldTurn[0] = false;
		shouldTurn[1] = false;
		shouldTurn[2] = false;
		shouldTurn[3] = false;
	}
	void initEyesFrames() {
		eyesClips.resize(GHOST_EYE_FRAMES);
		for (int i = 0; i < GHOST_EYE_FRAMES; i++) {
			eyesClips[i].x = i * BLOCKSIZE32;
			eyesClips[i].y = 0;
			eyesClips[i].w = BLOCKSIZE32;
			eyesClips[i].h = BLOCKSIZE32;
		}
	}

	void renderGhost(SDL_Renderer* renderer);
	void tickEyesFrames() {
		currentEyesFrames = currentEyesFrames + 1;
		if (currentEyesFrames / (GHOST_EYE_FRAMES - 1) >= (GHOST_EYE_FRAMES - 1)) {
			currentEyesFrames = 0;
		}
	}
};












#endif GHOST_H

