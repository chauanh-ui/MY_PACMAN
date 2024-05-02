//#include "BaseObject.h"
//
//BaseObject::BaseObject(const std::string imagePath, SDL_Renderer* renderer) {
//	texture = new Texture(imagePath, renderer);
//	currentFrame = 0;
//	int x = 0;
//	int y = 0;
//	speed = BLOCKSIZE16;
//	/*startPosision.x = getStartX();
//	startPosision.y = getStartY();*/
//
//}
//
//void BaseObject::checkCollisionWithWalls(int _x, int _y) {
//	int center_x = x + BLOCKSIZE16;
//	int center_y = y + BLOCKSIZE16;
//	int row = center_y / BLOCKSIZE16;
//	int col = center_x / BLOCKSIZE16;
//	if (col == 0) {
//		turnAllows[DIRECTION_LEFT] = false;
//	}
//	if (col == TOTAL_BLOCK_X - 1) {
//		turnAllows[DIRECTION_RIGHT] = false;
//	}
//	if (row == 3) {
//		turnAllows[DIRECTION_UP] = false;
//	}
//	if (row > 0 && board[row - 1][col] == WALL) {
//		turnAllows[DIRECTION_UP] = false;
//	}
//	if (row < TOTAL_BLOCK_Y - 1 && board[row + 1][col] == WALL) {
//		turnAllows[DIRECTION_DOWN] = false;
//	}
//	if (col > 0 && board[row][col - 1] == WALL) {
//		turnAllows[DIRECTION_LEFT] = false;
//	}
//	if (col < TOTAL_BLOCK_X - 1 && board[row][col + 1] == WALL) {
//		turnAllows[DIRECTION_RIGHT] = false;
//	}
//}
//void BaseObject::resetTurnAllows() {
//	turnAllows[0] = true;
//	turnAllows[1] = true;
//	turnAllows[2] = true;
//	turnAllows[3] = true;
//}
//
//void BaseObject::renderObject(SDL_Renderer* renderer, SDL_Rect* clip, double angle, SDL_RendererFlip flip) {
//	texture->render(renderer, x, y, clip, angle, flip);
//}
//
//
//void BaseObject::tick() {
//	currentFrame = (currentFrame + 1) % numberOfFrames;
//}