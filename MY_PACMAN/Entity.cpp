#include "Entity.h"
//
//Entity::Entity(int _entityType, SDL_Renderer* renderer) {
//	entityType = _entityType;
//	currentFrames = 0;
//	isAlive = true;
//	facing = 0;
//}
//
//void Entity::initFrames() {
//	for (int i = 0; i < totalFrames; i++) {
//		clips[i].x = i * BLOCKSIZE32;
//		clips[i].y = 0;
//		clips[i].w = BLOCKSIZE32;
//		clips[i].h = BLOCKSIZE32;
//	}
//}
//
//void Entity::tick() {
//	currentFrames = currentFrames + 1;
//	if (currentFrames / totalFrames >= totalFrames) {
//		currentFrames = 0;
//	}
//	
//}
//
////void Entity::setContainer(SDL_Rect& _container) {
////	container = container;
////}
//
//void Entity::renderEntity(SDL_Renderer* renderer) {
//	entityTexture->setSrc(clips[currentFrames / totalFrames]); // clips nay lay dau ra ??? -> cho vao hay gi
//	entityTexture->setDst(currentPos); //update thang khi goi ham move
//	entityTexture->render(renderer, 90.0f * (double) facing);
//	SDL_Delay(20);
//	tick();
//}
//
//void Entity::renderToStartPosition(SDL_Renderer* renderer) {
//	entityTexture->setSrc(clips[currentFrames / totalFrames]); // clips nay lay dau ra ??? -> cho vao hay gi
//	entityTexture->setDst(startPos); //update thang khi goi ham move
//	entityTexture->render(renderer, 90.0f * (double) facing);
//	tick();
//}
//
//void Entity::resetTurnAllows() {
//	turnAllows[0] = true;
//	turnAllows[1] = true;
//	turnAllows[2] = true;
//	turnAllows[3] = true;
//}
//
//
//
//void Entity::checkCollisionWithWalls(int container_x, int container_y) {
//	int center_x = container_x - OFFSET_X + BLOCKSIZE16;
//	int center_y = container_y - OFFSET_Y + BLOCKSIZE16;
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

Entity::Entity(EntityType MyIdentity) {
	Identity = MyIdentity;
	Speed = 2;
	Direction = 0;
	Facing = 0;
	LifeStatement = true;
}

unsigned char Entity::GetIdentity() {
	return Identity;
}

unsigned char Entity::GetSpeed() {
	return Speed;
}

unsigned char Entity::GetDirection() {
	return Direction;
}

unsigned char Entity::GetFacing() {
	return Facing;
}

bool Entity::IsAlive() {
	return LifeStatement;
}

void Entity::ModSpeed(unsigned char NewSpeed) {
	Speed = NewSpeed;
}

void Entity::ModDirection(unsigned char NewDirection) {
	Direction = NewDirection;
}

void Entity::ModFacing(unsigned char NewFacing) {
	Facing = NewFacing;
}

void Entity::ModLifeStatement(bool NewLifeStatement) {
	LifeStatement = NewLifeStatement;
}

void Entity::GetPossiblePosition(short& x, short& y, unsigned char mover) {
	switch (mover) {
	case Right:
		x++;
		break;
	case Up:
		y--;
		break;
	case Left:
		x--;
		break;
	case Down:
		y++;
		break;
	default:
		break;
	}
}

void Entity::CharBoardPos(unsigned char SideDir, Position& BoardPos, float cell_x, float cell_y) {
	switch (SideDir) {
	case 0:
		BoardPos.ModX(static_cast<short>(floor(cell_x)));
		BoardPos.ModY(static_cast<short>(floor(cell_y)));
		break;
	case 1:
		BoardPos.ModX(static_cast<short>(ceil(cell_x)));
		BoardPos.ModY(static_cast<short>(floor(cell_y)));
		break;
	case 2:
		BoardPos.ModX(static_cast<short>(floor(cell_x)));
		BoardPos.ModY(static_cast<short>(ceil(cell_y)));
		break;
	case 3:
		BoardPos.ModX(static_cast<short>(ceil(cell_x)));
		BoardPos.ModY(static_cast<short>(ceil(cell_y)));
		break;
	default:
		break;
	}
}

bool Entity::WallCollision(short x, short y, unsigned char ActualMap[], bool CanUseDoor) {
	float cell_x = x / static_cast<float>(BlockSize24);
	float cell_y = y / static_cast<float>(BlockSize24);
	Position BoardPos;
	for (unsigned char SideDir = 0; SideDir < 4; SideDir++) {
		this->CharBoardPos(SideDir, BoardPos, cell_x, cell_y);
		if (BlockType::Wall == ActualMap[BoardWidth * BoardPos.GetY() + abs(BoardPos.GetX() % BoardWidth)]) {
			return true;
		}
		else if (BlockType::Door == ActualMap[BoardWidth * BoardPos.GetY() + abs(BoardPos.GetX() % BoardWidth)]) {
			if (CanUseDoor)
				return false;
			else
				return true;
		}
	}
	return false;
}

void Entity::Move(unsigned char mover) {
	switch (mover) {
	case Right:
		this->ModX(this->GetX() + 1);
		break;
	case Up:
		this->ModY(this->GetY() - 1);
		break;
	case Left:
		this->ModX(this->GetX() - 1);
		break;
	case Down:
		this->ModY(this->GetY() + 1);
		break;
	default:
		break;
	}
}

void Entity::CheckWrap() {
	if (this->GetX() > WindowWidth + BlockSize24)
		this->ModX(-BlockSize24);
	if (this->GetX() < -BlockSize24)
		this->ModX(WindowWidth + BlockSize24);
}

bool Entity::IsColliding(Position other) {
	if (other.GetX() > this->GetX() - BlockSize24 && other.GetX() < this->GetX() + BlockSize24) {
		if (other.GetY() > this->GetY() - BlockSize24 && other.GetY() < this->GetY() + BlockSize24)
			return true;
	}
	return false;
}

