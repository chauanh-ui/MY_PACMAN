#include "Entity.h"

Entity::Entity(int _entityType, SDL_Renderer* renderer) {
	entityType = _entityType;
	currentFrames = 0;
	isAlive = true;
	facing = 0;
}

void Entity::initFrames() {
	for (int i = 0; i < totalFrames; i++) {
		clips[i].x = i * BLOCKSIZE32;
		clips[i].y = 0;
		clips[i].w = BLOCKSIZE32;
		clips[i].h = BLOCKSIZE32;
	}
}

void Entity::tick() {
	currentFrames = currentFrames + 1;
	std::cout << totalFrames << std::endl;
	if (currentFrames / totalFrames >= totalFrames) {
		currentFrames = 0;
	}
	
}

//void Entity::setContainer(SDL_Rect& _container) {
//	container = container;
//}

void Entity::renderEntity(SDL_Renderer* renderer) {
	entityTexture->setSrc(clips[currentFrames / totalFrames]); // clips nay lay dau ra ??? -> cho vao hay gi
	entityTexture->setDst(currentPos); //update thang khi goi ham move
	entityTexture->render(renderer, 90.0f * (double) facing);
	SDL_Delay(20);
	tick();
}

void Entity::renderToStartPosition(SDL_Renderer* renderer) {
	entityTexture->setSrc(clips[currentFrames / totalFrames]); // clips nay lay dau ra ??? -> cho vao hay gi
	entityTexture->setDst(startPos); //update thang khi goi ham move
	entityTexture->render(renderer, 90.0f * (double) facing);
	tick();
}

void Entity::resetTurnAllows() {
	turnAllows[0] = true;
	turnAllows[1] = true;
	turnAllows[2] = true;
	turnAllows[3] = true;
}



void Entity::checkCollisionWithWalls(int container_x, int container_y) {
	int center_x = container_x - OFFSET_X + BLOCKSIZE16;
	int center_y = container_y - OFFSET_Y + BLOCKSIZE16;
	int row = center_y / BLOCKSIZE16;
	int col = center_x / BLOCKSIZE16;
	if (col == 0) {
		turnAllows[DIRECTION_LEFT] = false;
	}
	if (col == TOTAL_BLOCK_X - 1) {
		turnAllows[DIRECTION_RIGHT] = false;
	}
	if (row == 3) {
		turnAllows[DIRECTION_UP] = false;
	}
	if (row > 0 && board[row - 1][col] == WALL) {
		turnAllows[DIRECTION_UP] = false;
	}
	if (row < TOTAL_BLOCK_Y - 1 && board[row + 1][col] == WALL) {
		turnAllows[DIRECTION_DOWN] = false;
	}
	if (col > 0 && board[row][col - 1] == WALL) {
		turnAllows[DIRECTION_LEFT] = false;
	}
	if (col < TOTAL_BLOCK_X - 1 && board[row][col + 1] == WALL) {
		turnAllows[DIRECTION_RIGHT] = false;
	}
}


