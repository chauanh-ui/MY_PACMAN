#include "Pacman.h"
#include "Entity.h"
#include <vector>

Pacman::Pacman(SDL_Renderer* renderer): Entity (PACMAN, renderer) {
	std::cout << "Khoi tao pacman\n";
	speed = BLOCKSIZE16;
	entityTexture = new Texture(PACMAN_RIGHT_PATH, renderer);
	std::cout << "Khoi tao texture, load anh\n";
	setStartPos(PACMAN_START_POS);
	currentPos = startPos;
	setTotalFrames(LIVING_PAC_FRAMES);
	std::cout << "Khoi tao vector<rect> cac frames\n";
	std::cout << totalFrames << std::endl;
	clips.resize(totalFrames);
	std::cout << clips.size();
	initFrames();
}
void Pacman::move(SDL_Event& e) {
	std::cout << "chay den ham move";
	std::cout << "x: " << currentPos.x << " " << "y: " << currentPos.y;
	resetTurnAllows();
	checkCollisionWithWalls(currentPos.x, currentPos.y);
	for (int i = 0; i < 4; i++) {
		std::cout << turnAllows[i] << " ";
	}
	if (e.key.keysym.sym == SDLK_UP) {
		currentPos.y -= speed;
		if (!turnAllows[DIRECTION_UP]) {
			currentPos.y += speed;
		}
		facing = DIRECTION_UP;
	}
	else if (e.key.keysym.sym == SDLK_DOWN) {
		currentPos.y += speed;
		if (!turnAllows[DIRECTION_DOWN]) {
			currentPos.y -= speed;
		}
		facing = DIRECTION_DOWN;
	}
	else if (e.key.keysym.sym == SDLK_LEFT) {
		currentPos.x -= speed;
		if (!turnAllows[DIRECTION_LEFT]) {
			currentPos.x += speed;
		}
		facing = DIRECTION_LEFT;
	}
	else if (e.key.keysym.sym == SDLK_RIGHT) {
		currentPos.x += speed;
		if (!turnAllows[DIRECTION_RIGHT]) {
			currentPos.x -= speed;
		}
		facing = DIRECTION_RIGHT;
	}
	std::cout << "Chay het 1 luot ham move\n";
	std::cout << "x: " << currentPos.x << " y: " << currentPos.y << std::endl;
	std::cout << "facing: " << facing << std::endl;
}
void Pacman::eat() {
	
}


