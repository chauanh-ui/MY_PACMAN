#include "Pacman.h"
#include "Entity.h"
#include <vector>

Pacman::Pacman(SDL_Renderer* renderer): Entity (PACMAN, renderer) {
	speed = BLOCKSIZE16;
	entityTexture = new Texture(PACMAN_RIGHT_PATH, renderer);
	setStartPos(PACMAN_START_POS);
	currentPos = startPos;
	setTotalFrames(LIVING_PAC_FRAMES);
	clips.resize(totalFrames);
	initFrames();
}
void Pacman::move(SDL_Event& e) {

	resetTurnAllows();
	checkCollisionWithWalls(currentPos.x, currentPos.y);
	if (e.key.keysym.sym == SDLK_UP) {
		currentPos.y -= speed;
		
		if (!turnAllows[DIRECTION_UP]) {
			currentPos.y += speed;
		}
		setFacing(DIRECTION_UP);

	}
	else if (e.key.keysym.sym == SDLK_DOWN) {
		currentPos.y += speed;
		if (!turnAllows[DIRECTION_DOWN]) {
			currentPos.y -= speed;
		}
		setFacing(DIRECTION_DOWN);
	}
	else if (e.key.keysym.sym == SDLK_LEFT) {
		currentPos.x -= speed;
		if (!turnAllows[DIRECTION_LEFT]) {
			currentPos.x += speed;
		}
		setFacing(DIRECTION_LEFT);
	}
	else if (e.key.keysym.sym == SDLK_RIGHT) {
		currentPos.x += speed;
		if (!turnAllows[DIRECTION_RIGHT]) {
			currentPos.x -= speed;
		}
		setFacing(DIRECTION_RIGHT);
	}
	eat(currentPos.x, currentPos.y);
	if (isEnergize) {
		startEnergizedTime();
		if (energizedStartTime == ENERGIZED_DURATION) {
			resetEnergizedStatus();
		}
	}
	
}
void Pacman::eat(int x, int y) {
	int center_x = x - OFFSET_X + BLOCKSIZE16;
	int center_y = y - OFFSET_Y + BLOCKSIZE16;
	int row = center_y / BLOCKSIZE16;
	int col = center_x / BLOCKSIZE16;
	if (board[row][col] == PELLET) {
		board[row][col] = NOTHING;
		score += PELLET_SCORE;

	}
	else if (board[row][col] == ENERGIZER) {
		board[row][col] = NOTHING;
		score += ENERGIZER_SCORE;
		isEnergize = true;
	}
}
Pacman::~Pacman()
{
	;
}



