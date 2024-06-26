#include "Pac.h"

Pac::Pac() :Entity(EntityType::ePacMan) {
	// if (pacType == 0) (==1, ==2)
	if (isPlayExtra) {
		LivingPac.loadFromFile("Textures/PacMan16.png");
		DeathPac.loadFromFile("Textures/GameOver16.png");
		InitFrames(LivingPacFrames, LivingPacSpriteClips, 16);
		InitFrames(DeathPacFrames, DeathPacSpriteClips, 16);
	}
	else {
		LivingPac.loadFromFile("Textures/PacMan32.png");
		DeathPac.loadFromFile("Textures/GameOver32.png");
		InitFrames(LivingPacFrames, LivingPacSpriteClips);
		InitFrames(DeathPacFrames, DeathPacSpriteClips);
	}
	// if (pacType == 0)
	//DeathPac.loadFromFile("Textures/GameOver32.png");
	//
	//  {
	//	InitFrames(LivingPacFrames, LivingPacSpriteClips, 16);
	//	//InitFrames(DeathPacFrames, DeathPacSpriteClips, 16);
	//} 
	//InitFrames(LivingPacFrames, LivingPacSpriteClips);
	//InitFrames(DeathPacFrames, DeathPacSpriteClips);
	CurrLivingPacFrame = 0;
	CurrDeathPacFrame = 0;
	EnergyStatus = false;
	DeadAnimationStatement = false;
}

Pac::~Pac() {
	LivingPac.free();
	DeathPac.free();
}

void Pac::UpdatePos(std::vector<unsigned char>& mover, unsigned char ActualMap[]) {
	for (unsigned char i = 0; i < this->GetSpeed(); i++) {
		short TempX = this->GetX();
		short TempY = this->GetY();
		this->GetPossiblePosition(TempX, TempY, mover.at(0));
		if (!this->WallCollision(TempX, TempY, ActualMap)) {
			this->UpdateCurrentLivingPacFrame();
			this->Move(mover.at(0));
			this->SetFacing(mover.at(0));
			this->ModDirection(mover.at(0));
		}
		else
			this->WallCollisionFrame();
		if (mover.size() != 1 && mover.at(0) != mover.at(1)) {
			TempX = this->GetX();
			TempY = this->GetY();
			this->GetPossiblePosition(TempX, TempY, mover.at(1));
			if (!this->WallCollision(TempX, TempY, ActualMap)) {
				this->UpdateCurrentLivingPacFrame();
				this->Move(mover.at(1));
				this->SetFacing(mover.at(1));
				this->ModDirection(mover.at(1));
				mover.erase(mover.begin());
			}
		}
		this->CheckWrap();
	}
}

unsigned char Pac::FoodCollision(unsigned char ActualMap[]) {
	float cell_x = this->GetX() / static_cast<float>(BlockSize24);
	float cell_y = this->GetY() / static_cast<float>(BlockSize24);
	Position BoardPos;
	for (unsigned char SideDir = 0; SideDir < 4; SideDir++) {
		this->CharBoardPos(SideDir, BoardPos, cell_x, cell_y);
		if (BlockType::Pellet == ActualMap[BoardWidth * BoardPos.GetY() + BoardPos.GetX()]) {
			ActualMap[BoardWidth * BoardPos.GetY() + BoardPos.GetX()] = BlockType::Nothing;
			return 0;
		}
		else if (BlockType::Energizer == ActualMap[BoardWidth * BoardPos.GetY() + BoardPos.GetX()]) {
			ActualMap[BoardWidth * BoardPos.GetY() + BoardPos.GetX()] = BlockType::Nothing;
			return 1;
		}
	}
	return 2;
}

bool Pac::IsEnergized() {
	return EnergyStatus;
}

void Pac::ChangeEnergyStatus(bool NewEnergyStatus) {
	EnergyStatus = NewEnergyStatus;
}

void Pac::SetFacing(unsigned char mover) {
	switch (mover) {
	case Right:
		this->ModFacing(0);
		break;
	case Up:
		this->ModFacing(3);
		break;
	case Left:
		this->ModFacing(2);
		break;
	case Down:
		this->ModFacing(1);
		break;
	default:
		break;
	}
}

bool Pac::IsDeadAnimationEnded() {
	return DeadAnimationStatement;
}

void Pac::ModDeadAnimationStatement(bool NewDeadAnimationStatement) {
	DeadAnimationStatement = NewDeadAnimationStatement;
}

void Pac::UpdateCurrentLivingPacFrame() {
	CurrLivingPacFrame++;
	if (CurrLivingPacFrame / (LivingPacFrames * 4) >= LivingPacFrames) {
		CurrLivingPacFrame = 0;
	}
}

void Pac::ResetCurrentLivingFrame() {
	CurrLivingPacFrame = 0;
}

void Pac::WallCollisionFrame() {
	CurrLivingPacFrame = 32;
}

void Pac::Draw() {
	if (this->IsAlive()) {
		CurrentClip = &LivingPacSpriteClips[CurrLivingPacFrame / (LivingPacFrames * 4)];
		if (isPlayExtra) {
			LivingPac.render(this->GetX(), this->GetY(), this->GetFacing(), CurrentClip);
		}
		else {
			LivingPac.render(this->GetX() - 8, this->GetY() - 8, this->GetFacing(), CurrentClip);
		}
		
		
	}
	else {
		CurrentClip = &DeathPacSpriteClips[CurrDeathPacFrame / DeathPacFrames];
		if (isPlayExtra) {
			DeathPac.render(this->GetX(), this->GetY(), this->GetFacing(), CurrentClip);
		}
		else {
			DeathPac.render(this->GetX() - 8, this->GetY() - 8, this->GetFacing(), CurrentClip);
		}
		
		CurrDeathPacFrame++;
		if (CurrDeathPacFrame / DeathPacFrames >= DeathPacFrames) {
			DeadAnimationStatement = true;
			CurrDeathPacFrame = 0;
		}
	}
}