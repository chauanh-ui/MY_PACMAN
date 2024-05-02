#include "Entity.h"

Entity::Entity(int _entityType, SDL_Renderer* renderer) {
	entityType = _entityType;
	currentFrames = 0;
	isAlive = true;
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
	std::cout << "Tang currentFrame\n";
	currentFrames = currentFrames + 1;
	std::cout << totalFrames << std::endl;
	if (currentFrames / totalFrames >= totalFrames) {
		std::cout << "chay vo if\n";
		currentFrames = 0;
	}
	
}

//void Entity::setContainer(SDL_Rect& _container) {
//	container = container;
//}

void Entity::renderEntity(SDL_Renderer* renderer) {
	std::cout << "currentFrame: " << currentFrames << std::endl;
	entityTexture->setSrc(clips[currentFrames / totalFrames]); // clips nay lay dau ra ??? -> cho vao hay gi
	entityTexture->setDst(currentPos); //update thang khi goi ham move
	entityTexture->render(renderer, 90 * facing, SDL_FLIP_VERTICAL);
	SDL_Delay(20);
	tick();
}

void Entity::renderToStartPosition(SDL_Renderer* renderer) {
	entityTexture->setSrc(clips[currentFrames / totalFrames]); // clips nay lay dau ra ??? -> cho vao hay gi
	entityTexture->setDst(startPos); //update thang khi goi ham move
	entityTexture->render(renderer, 90 * facing);
	SDL_Delay(20);
	tick();
}


//void Entity::move(SDL_Event& e) {
//	std::cout << "Chay den day" << std::endl;
//	resetTurnAllows();
//	checkCollisionWithWalls(currentPos.x, currentPos.y);
//	for (int i = 0; i < 4; i++) {
//		std::cout << turnAllows[i] << " ";
//	}
//	if (e.key.keysym.sym == SDLK_UP) {
//		currentPos.y -= speed;
//		/*if (container.y < 0) {
//			container.y = 0;
//		}*/
//		//checkCollisionWithWalls(container.x, container.y);
//		if (!turnAllows[DIRECTION_UP]) {
//			currentPos.y += speed;
//		}
//	}
//	else if (e.key.keysym.sym == SDLK_DOWN) {
//		currentPos.y += speed;
//		/*if (container.y + container.h > WINDOW_HEIGHT) {
//			container.y = WINDOW_HEIGHT - container.h;
//		}*/
//		//checkCollisionWithWalls(container.x, container.y);
//		if (!turnAllows[DIRECTION_DOWN]) {
//			currentPos.y -= speed;
//		}
//	}
//	else if (e.key.keysym.sym == SDLK_LEFT) {
//		currentPos.x -= speed;
//		/*if (container.x < 0) {
//			container.x = 0;
//		}*/
//		//checkCollisionWithWalls(container.x, container.y);
//		if (!turnAllows[DIRECTION_LEFT]) {
//			currentPos.x += speed;
//		}
//	}
//	else if (e.key.keysym.sym == SDLK_RIGHT) {
//		currentPos.x += speed;
//		/*if (container.x + container.w > WINDOW_WIDTH) {
//			container.x = WINDOW_WIDTH - container.w;
//		}*/
//		//checkCollisionWithWalls(container.x, container.y);
//		if (!turnAllows[DIRECTION_RIGHT]) {
//			currentPos.x -= speed;
//		}
//	}
//	for (int i = 0; i < 4; i++) {
//		std::cout << turnAllows[i] << " ";
//	}
//	std::cout << "vi tri: " << currentPos.x << " " << currentPos.y << "Het 1 luot" << std::endl;
//}
void Entity::resetTurnAllows() {
	turnAllows[0] = true;
	turnAllows[1] = true;
	turnAllows[2] = true;
	turnAllows[3] = true;
}



void Entity::checkCollisionWithWalls(int container_x, int container_y) {
	int center_x = container_x + BLOCKSIZE16;
	int center_y = container_y + BLOCKSIZE16;
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
		std::cout << "len" << std::endl;
	}
	if (row < TOTAL_BLOCK_Y - 1 && board[row + 1][col] == WALL) {
		turnAllows[DIRECTION_DOWN] = false;
		std::cout << "xuong" << std::endl;
	}
	if (col > 0 && board[row][col - 1] == WALL) {
		turnAllows[DIRECTION_LEFT] = false;
		std::cout << "trai" << std::endl;
	}
	if (col < TOTAL_BLOCK_X - 1 && board[row][col + 1] == WALL) {
		turnAllows[DIRECTION_RIGHT] = false;
		std::cout << "phai" << std::endl;
	}
}


