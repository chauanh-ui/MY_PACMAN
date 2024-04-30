#include "Entity.h"

Entity::Entity(SDL_Renderer* renderer, const int _entityType) {
	std::string imagePath = "";
	entityType = _entityType;
	switch (entityType)
	{
	case PACMAN:
		src = PACMAN_IMAGE_SRC;
		container = PACMAN_IMAGE_CONTAINER;
		imagePath = PACMAN_IMAGE_PATH;
		speed = BLOCKSIZE16;
	case BLINKY:
		break;
	default:
		break;
	}
	center.x = container.x + container.w / 2;
	center.y = container.y + container.h / 2;
	std::cout << container.x << std::endl;
	entityTexture = new Texture(imagePath ,src, container, renderer);
}

void Entity::setContainer(SDL_Rect& _container) {
	container = container;
}

void Entity::renderEntity(SDL_Renderer* renderer) {
	entityTexture->setDst(container);
	entityTexture->render(renderer);
}

void Entity::renderToStartPosition(SDL_Renderer* renderer) {
	container = PACMAN_IMAGE_CONTAINER;
	renderEntity(renderer);
}


void Entity::move(SDL_Event& e) {
	std::cout << "Chay den day" << std::endl;
	resetTurnAllows();
	checkCollisionWithWalls(container.x, container.y);
	for (int i = 0; i < 4; i++) {
		std::cout << turnAllows[i] << " ";
	}
	if (e.key.keysym.sym == SDLK_UP) {
		container.y -= speed;
		/*if (container.y < 0) {
			container.y = 0;
		}*/
		//checkCollisionWithWalls(container.x, container.y);
		if (!turnAllows[DIRECTION_UP]) {
			container.y += speed;
		}
	}
	else if (e.key.keysym.sym == SDLK_DOWN) {
		container.y += speed;
		/*if (container.y + container.h > WINDOW_HEIGHT) {
			container.y = WINDOW_HEIGHT - container.h;
		}*/
		//checkCollisionWithWalls(container.x, container.y);
		if (!turnAllows[DIRECTION_DOWN]) {
			container.y -= speed;
		}
	}
	else if (e.key.keysym.sym == SDLK_LEFT) {
		container.x -= speed;
		/*if (container.x < 0) {
			container.x = 0;
		}*/
		//checkCollisionWithWalls(container.x, container.y);
		if (!turnAllows[DIRECTION_LEFT]) {
			container.x += speed;
		}
	}
	else if (e.key.keysym.sym == SDLK_RIGHT) {
		container.x += speed;
		/*if (container.x + container.w > WINDOW_WIDTH) {
			container.x = WINDOW_WIDTH - container.w;
		}*/
		//checkCollisionWithWalls(container.x, container.y);
		if (!turnAllows[DIRECTION_RIGHT]) {
			container.x -= speed;
		}
	}
	for (int i = 0; i < 4; i++) {
		std::cout << turnAllows[i] << " ";
	}
	std::cout << "vi tri: " << container.x << " " << container.y << "Het 1 luot" << std::endl;
}
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


int Entity::getNumericMapPos(int row, int col) {
	return board[row][col];
}
