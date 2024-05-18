#include "Ghost.h"
#include <iostream>

//
//
//Ghost::Ghost(SDL_Renderer* renderer) : Entity(GHOST, renderer) {
//	currentEyesFrames = 0;
//	facing = 0;
//	speed = BLOCKSIZE16 / 2;
//	entityTexture = new Texture(GHOST_IMAGE_PATH, renderer);
//	eyesTexture = new Texture(EYES_IMAGE_PATH, renderer);
//	setTotalFrames(GHOST_BODY_FRAMES);
//	clips.resize(totalFrames);
//	initFrames();
//	initEyesFrames();
//}
//
//void Ghost::renderGhost(SDL_Renderer* renderer) {
//	if (isFrighten) {
//		entityTexture->setColor(BLUE);
//	}
//	renderEntity(renderer);
//	eyesTexture->setSrc(eyesClips[currentEyesFrames / GHOST_EYE_FRAMES]); // clips nay lay dau ra ??? -> cho vao hay gi
//	eyesTexture->setDst(currentPos);//update thang khi goi ham move
//	if (isFrighten) {
//		eyesTexture->setSrc(eyesClips[GHOST_EYE_FRAMES - 1]);
//	}
//	eyesTexture->render(renderer);
//	SDL_Delay(20);
//	tickEyesFrames();
//}
//
//void Ghost::moving(Pacman* pacman) {
//	setIsFrighten(pacman->getEnergizedStatus());
//	if (!isFrighten) {
//		setTarget(pacman->currentPos.x, pacman->currentPos.y);
//		resetTurnAllows();
//		resetDistance();
//		checkCollisionWithWalls(currentPos.x, currentPos.y);
//		if (turnAllows[direction] == false) {
//			updateDirection(target.x, target.y);
//		}
//		move(direction);
//	}
//	else {
//		setTarget(home.x, home.y);
//		resetTurnAllows();
//		checkCollisionWithWalls(currentPos.x, currentPos.y);
//		if (turnAllows[direction] == false) {
//			updateDirection(target.x, target.y);
//		}
//		move(direction);
//	}
//	timer++;
//}
//
//void Ghost::updateDirection(int targetX, int targetY) {
//	if (targetX < currentPos.x) {
//		nextPossibleDirection.push_back(DIRECTION_LEFT);
//	}
//	if (targetY > currentPos.y) {
//		nextPossibleDirection.push_back(DIRECTION_DOWN);
//	}
//	if (targetX > currentPos.x) {
//		nextPossibleDirection.push_back(DIRECTION_RIGHT);
//	}
//	if (targetY < currentPos.y) {
//		nextPossibleDirection.push_back(DIRECTION_UP);
//	}
//	for (int i = 0; i < nextPossibleDirection.size(); i++) {
//		if (turnAllows[nextPossibleDirection[i]]) {
//			direction = nextPossibleDirection[i];
//			return;
//		}
//	}
//}
//
//Ghost::~Ghost() {
//	delete eyesTexture;
//}
//
//void Ghost::moveGhost(SDL_Event& e) {
//	resetTurnAllows();
//	checkCollisionWithWalls(currentPos.x, currentPos.y);
//	if (e.key.keysym.sym == SDLK_w) {
//		currentPos.y -= speed;
//
//		if (!turnAllows[DIRECTION_UP]) {
//			currentPos.y += speed;
//		}
//		//setFacing(DIRECTION_UP);
//
//	}
//	else if (e.key.keysym.sym == SDLK_s) {
//		currentPos.y += speed;
//		if (!turnAllows[DIRECTION_DOWN]) {
//			currentPos.y -= speed;
//		}
//		//setFacing(DIRECTION_DOWN);
//	}
//	else if (e.key.keysym.sym == SDLK_a) {
//		currentPos.x -= speed;
//		if (!turnAllows[DIRECTION_LEFT]) {
//			currentPos.x += speed;
//		}
//		//setFacing(DIRECTION_LEFT);
//	}
//	else if (e.key.keysym.sym == SDLK_d) {
//		currentPos.x += speed;
//		if (!turnAllows[DIRECTION_RIGHT]) {
//			currentPos.x -= speed;
//		}
//		//setFacing(DIRECTION_RIGHT);
//	}
//}
Ghost::Ghost(SDL_Color MyColor, EntityType MyIdentity) : Entity(MyIdentity) {
	if (isPlayExtra) {
		Body.loadFromFile("Textures/GhostBody16.png");
		Eyes.loadFromFile("Textures/GhostEyes16.png");
		InitFrames(GhostBodyFrames, GhostBodySpriteClips, 16);
		InitFrames(GhostEyeFrames, GhostEyeSpriteClips, 16);
	}
	else {
		Body.loadFromFile("Textures/GhostBody32.png");
		Eyes.loadFromFile("Textures/GhostEyes32.png");
		InitFrames(GhostBodyFrames, GhostBodySpriteClips);
		InitFrames(GhostEyeFrames, GhostEyeSpriteClips);
	}

	/*Body.loadFromFile("Textures/GhostBody32.png");
	Eyes.loadFromFile("Textures/GhostEyes32.png");
	InitFrames(GhostBodyFrames, GhostBodySpriteClips);
	InitFrames(GhostEyeFrames, GhostEyeSpriteClips);*/


	Color = MyColor;
	CurrentBodyFrame = 0;
	CanUseDoor = false;
	Status = false;
	DoorTarget.ModCoords(13 * BlockSize24 + BlockSize24 / 2, 15 * BlockSize24);
}

Ghost::~Ghost() {
	Body.free();
	Eyes.free();
}

bool Ghost::IsTargetToCalculate(Pac& mPac) {

	if (!this->IsAlive()) {
		CanUseDoor = true;
		Target.ModPos(Home);
		if (this->GetPos() == Home.GetPos())
			this->ModLifeStatement(true);
		return false;
	}

	if (this->IsHome() && mPac.IsEnergized()) {
		if (this->GetPos() == Home.GetPos())
			Target.ModY(this->Home.GetY() - BlockSize24);
		else if (this->GetX() == Home.GetX() && this->GetY() == Home.GetY() - BlockSize24)
			Target.ModY(this->Home.GetY());
		return false;
	}

	if (this->IsHome() && this->IsAlive()) {
		CanUseDoor = true;
		Target.ModPos(this->DoorTarget);
		return false;
	}

	CanUseDoor = false;
	switch (Status) {
	case false:
		return true;
	case true:
		Target.ModPos(this->ScatterTarget);
		return false;
	}

}

void Ghost::PossDirsBubbleSort(std::vector<float>& Distances, std::vector<unsigned char>& PossibleDirections) {
	for (unsigned char i = 0; i < Distances.size(); i++) {
		for (unsigned char j = 0; j < Distances.size(); j++) {
			if (Distances.at(i) < Distances.at(j)) {
				float temp1 = Distances.at(i);
				Distances.at(i) = Distances.at(j);
				Distances.at(j) = temp1;
				unsigned char temp2 = PossibleDirections.at(i);
				PossibleDirections.at(i) = PossibleDirections.at(j);
				PossibleDirections.at(j) = temp2;
			}
		}
	}
}

void Ghost::CalculateDirection(unsigned char ActualMap[]) {
	std::vector<float> Distances;
	std::vector<unsigned char> PossibleDirections;
	for (unsigned char i = 0; i < 4; i++) {
		short x = this->GetX();
		short y = this->GetY();
		this->GetPossiblePosition(x, y, i);
		if (!this->WallCollision(x, y, ActualMap, CanUseDoor)) {
			float DistX = abs(x - this->Target.GetX());
			if (DistX > WindowWidth / 2)
				DistX = WindowWidth - DistX;
			float Dist = static_cast<float>(sqrt(pow(DistX, 2) + pow(y - Target.GetY(), 2)));
			Distances.push_back(Dist);
			PossibleDirections.push_back(i);
		}
	}

	if (PossibleDirections.size() == 1) {
		this->ModDirection(PossibleDirections.at(0));
		return;
	}

	this->PossDirsBubbleSort(Distances, PossibleDirections);

	for (unsigned char i = 0; i < PossibleDirections.size(); i++) {
		if (PossibleDirections.at(i) != (this->GetDirection() + 2) % 4) {
			this->ModDirection(PossibleDirections.at(i));
			return;
		}
	}
}

bool Ghost::IsHome() {
	if (this->GetX() > 11 * BlockSize24 && this->GetX() < 17 * BlockSize24) {
		if (this->GetY() > 15 * BlockSize24 && this->GetY() < 18 * BlockSize24)
			return true;
	}
	return false;
}

void Ghost::ModStatus(bool NewStatus) {
	Status = NewStatus;
}

void Ghost::UpdateStatus(Pac& mPac, bool TimedStatus) {

	if (mPac.IsEnergized()) {
		if (!Status)
			Status = true;
		return;
	}

	switch (TimedStatus) {
	case false:
		if (Status)
			Status = false;
		return;
	case true:
		if (!Status)
			Status = true;
		return;
	}

}

void Ghost::UpdateFacing(Pac& mPac) {

	if (this->IsHome()) {
		if (this->GetDirection() == 3)
			this->ModFacing(3);
		else
			this->ModFacing(1);
		return;
	}

	if (mPac.IsEnergized()) {
		if (!this->IsAlive())
			this->ModFacing(this->GetDirection());
		else
			this->ModFacing(4);
		return;
	}

	this->ModFacing(this->GetDirection());

}

void Ghost::UpdateSpeed(Pac& mPac) {

	if (!this->IsAlive() && this->GetSpeed() != 6) {
		this->ModSpeed(6);
		return;
	}

	if (mPac.IsEnergized()) {
		if (this->GetSpeed() != 1)
			this->ModSpeed(1);
	}
	else {
		if (this->GetSpeed() != 2)
			this->ModSpeed(2);
	}

}

void Ghost::Draw(Pac& mPac, Timer mGhostTimer, unsigned short mTimerTarget) {
	if (mPac.IsEnergized() && this->IsAlive() && !this->IsHome()) {
		Body.setColor(0, 0, 255);
		if (mGhostTimer.GetTicks() > mTimerTarget - 2000) {
			if ((mGhostTimer.GetTicks() / 250) % 2 == 1) {
				Body.setColor(255, 255, 255);
				Eyes.setColor(255, 0, 0);
			}
			else {
				Eyes.setColor(255, 255, 255);
			}
		}
		else {
			Eyes.setColor(255, 255, 255);
		}
	}
	else {
		Eyes.setColor(255, 255, 255);
		Body.setColor(Color.r, Color.g, Color.b);
	}

	if (this->IsAlive()) {
		CurrentClip = &GhostBodySpriteClips[CurrentBodyFrame / GhostBodyFrames];

		if (isPlayExtra) {
			Body.render(this->GetX(), this->GetY(), 0, CurrentClip);
		}
		else {
			Body.render(this->GetX() - 8, this->GetY() - 8, 0, CurrentClip);
		}
	}
	CurrentClip = &GhostEyeSpriteClips[this->GetFacing()];
	std::cout << "ghostX: " << this->GetX() << " ghostY: " << this->GetY();

	if (isPlayExtra) {
		Eyes.render(this->GetX(), this->GetY(), 0, CurrentClip);
	}
	else {
		Eyes.render(this->GetX() - 8, this->GetY() - 8, 0, CurrentClip);
	}
	CurrentBodyFrame++;
	if (CurrentBodyFrame / GhostBodyFrames >= GhostBodyFrames) {
		CurrentBodyFrame = 0;
	}
}