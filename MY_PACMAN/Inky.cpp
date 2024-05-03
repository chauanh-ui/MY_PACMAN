#include "Inky.h"

Inky::Inky(SDL_Renderer* renderer) : Ghost(renderer){
	ghostType = INKY;
	setColor(PINK);
	setTextureColor();
	setStartPos(INKY_START_POS);
	currentPos = startPos;
}
Inky::~Inky() {
	;
}


