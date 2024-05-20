#include "Board.h"
#include "Globals.h"
#include <iostream>

MapColor Board::mapColor = MapColor::map_blue;
Board::Board() {
	// if (!isPlayExtra)
	// if (theme == darktheme)
	if (isPlayExtra) {
		switch (mazeTexture)
		{
		case water:
			WallTexture.loadFromFile("Textures/WallTexture/water.png");
			break;
		case sand:
			WallTexture.loadFromFile("Textures/WallTexture/sand.png");
			break;
		case wood:
			WallTexture.loadFromFile("Textures/WallTexture/wood.png");
			break;
		case leaf:
			WallTexture.loadFromFile("Textures/WallTexture/leaf.png");
			break;
		default:
			WallTexture.loadFromFile("Textures/WallTexture/sand.png");
			break;
		}
	}
	
	MapTexture.loadFromFile("Textures/Map16.png");
	PelletTexture.loadFromFile("Textures/Pellet24.png");
	EnergizerTexture.loadFromFile("Textures/Energizer24.png");
	DoorTexture.loadFromFile("Textures/Door16.png");
	LivesTexture.loadFromFile("Textures/Lives32.png");
	ScoreWordTexture.loadFromRenderedText("Score", White);
	HighScoreWordTexture.loadFromRenderedText("High Score", White);
	switch (mapColor) {
	case MapColor::map_blue:
		MapTexture.setColor(48, 84, 181);
		break;
	case MapColor::map_green:
		MapTexture.setColor(59, 141, 49);
		//std::cout << "green\n";
		break;
	case MapColor::map_red:
		MapTexture.setColor(209, 67, 129);
		//std::cout << "pink\n";
		break;
	case MapColor::map_light_blue:
		MapTexture.setColor(38, 177, 171);
		//std::cout << "purple\n";
		break;
	default:
		MapTexture.setColor(255, 255, 255);
		//std::cout << "default\n";
		break;
	};
	
	//std::cout << "set color map texture\n";
	this->ConvertSketch();
	Score = 0;
	IsExtra = false;
	Lives = 4;
}

Board::~Board() {
	// if (!isPlayExtra)
	WallTexture.free();
	MapTexture.free();
	PelletTexture.free();
	EnergizerTexture.free();
	DoorTexture.free();
	LivesTexture.free();
	ScoreWordTexture.free();
	ScoreTexture.free();
	HighScoreWordTexture.free();
	HighScoreTexture.free();
}

//void Board::UpdateCharBoard() {
// int rand = srand(0) % 4;
// std::string path = "Resources//" + to_string(rand) + ".txt";
// loadBoard(path); // vong for
// }

void Board::ConvertSketch() {
	// update charboard trc khi ham nay goi 
	// goi ham update charboard
	// dua vao bien toan cuc isPlayExtra 
	// update charboard o day
	if (isPlayExtra) {
		std::cout << "update charboard\n";
		CharBoard = extraBoards[board];
	}
	for (unsigned short i = 0; i < BoardHeight * BoardWidth; i++) {
		switch (CharBoard[i]) {
		case '#':
			NumericBoard[i] = BlockType::Wall;
			break;
		case '=':
			NumericBoard[i] = BlockType::Door;
			break;
		case '.':
			NumericBoard[i] = BlockType::Pellet;
			break;
		case 'o':
			NumericBoard[i] = BlockType::Energizer;
			break;
		default:
			NumericBoard[i] = BlockType::Nothing;
			break;
		}
	}
}

void Board::ResetPosition(Entity& mEntity) {
	char y = -1;
	for (unsigned short i = 0; i < BoardHeight * BoardWidth; i++) {
		unsigned char x = i % BoardWidth;
		if (x == 0)
			y++;
		if (CharBoard[i] == '0' && mEntity.GetIdentity() == EntityType::ePacMan) {
			mEntity.ModX(x * BlockSize24 + BlockSize24 / 2);
			mEntity.ModY(y * BlockSize24);
			return;
		}
		else if (CharBoard[i] == '1' && mEntity.GetIdentity() == EntityType::eBlinky) {
			mEntity.ModX(x * BlockSize24 + BlockSize24 / 2);
			mEntity.ModY(y * BlockSize24);
			return;
		}
		else if (CharBoard[i] == '2' && mEntity.GetIdentity() == EntityType::eInky) {
			mEntity.ModX(x * BlockSize24 + BlockSize24 / 2);
			mEntity.ModY(y * BlockSize24);
			return;
		}
		else if (CharBoard[i] == '3' && mEntity.GetIdentity() == EntityType::ePinky) {
			mEntity.ModX(x * BlockSize24 + BlockSize24 / 2);
			mEntity.ModY(y * BlockSize24);
			return;
		}
		else if (CharBoard[i] == '4' && mEntity.GetIdentity() == EntityType::eClyde) {
			mEntity.ModX(x * BlockSize24 + BlockSize24 / 2);
			mEntity.ModY(y * BlockSize24);
			return;
		}
		else if (CharBoard[i] == '5' && mEntity.GetIdentity() == EntityType::addedGhost) {
			mEntity.ModX(x * BlockSize24 + BlockSize24 / 2);
			mEntity.ModY(y * BlockSize24);
			return;
		}
	}
}

void Board::SetScore() {
	std::stringstream ss;
	ss << Score;
	ScoreTexture.loadFromRenderedText(ss.str(), White);
}

void Board::SetHighScore() {
	//std::cout << "Call setHighScore function\n";
	unsigned int High;
	std::ifstream HighScores("HighScore.txt");
	HighScores >> High;
	std::stringstream ss;
	if (Score > High) {
		ss << Score;
		//std::cout << "High score: " << Score << std::endl;
		std::ofstream HighScores("HighScore.txt");
		HighScores << ss.str();
	}
	else
		ss << High;
	HighScoreTexture.loadFromRenderedText(ss.str(), White);
	HighScores.close();
}

void Board::Draw(unsigned char ActualMap[], Timer MapAnimationTimer) {
	ScoreWordTexture.render();
	ScoreTexture.render(0, BlockSize32 - 5);
	HighScoreWordTexture.render(236);
	HighScoreTexture.render(236, BlockSize24 + 5);
	// Dua vao bien isPlayExtra de render lai Map Texture
	// Tao 1 ham rieng mapRender()
	if (!isPlayExtra) {
		MapTexture.render();
	}
	else {
		char y = -1;
		for (unsigned short i = 0; i < BoardHeight * BoardWidth; i++) {
			unsigned char x = i % BoardWidth;
			if (x == 0)
				y++;
			if (ActualMap[i] == BlockType::Wall)
				WallTexture.render(x * BlockSize24, y * BlockSize24);
		}
	}
	
	for (unsigned char i = 0; i < Lives; i++) {
		//LivesTexture.render(i * BlockSize32, 26 * BlockSize32 - BlockSize32 / 4);
		LivesTexture.render(i * BlockSize32, WindowHeight - 4 * BlockSize32);
		//std::cout << "WTF why dont render lives\n";
	}
	if (!MapAnimationTimer.isStarted()) {
		//DoorTexture.render(WindowWidth / 2 - 23, WindowHeight / 2 - 45);
		char y = -1;
		for (unsigned short i = 0; i < BoardHeight * BoardWidth; i++) {
			unsigned char x = i % BoardWidth;
			if (x == 0)
				y++;
			if (ActualMap[i] == BlockType::Pellet)
				PelletTexture.render(x * BlockSize24, y * BlockSize24);
			if (ActualMap[i] == BlockType::Energizer)
				EnergizerTexture.render(x * BlockSize24, y * BlockSize24);
		}
	}
	else {
		// If (!isPlayExtra)
		if ((MapAnimationTimer.GetTicks() / 250) % 2 == 1)
			MapTexture.setColor(255, 255, 255);
		else
			MapTexture.setColor(0, 0, 255);
	}
}

// actual map dc copy tu numericboard sang, numberic board dc chuyen tu charboard
void Board::CopyBoard(unsigned char ActualMap[]) {
	memcpy(ActualMap, NumericBoard, BoardHeight * BoardWidth);
}

bool Board::IsExtraLife() {
	if (!IsExtra && Score >= 10000) {
		IsExtra = true;
		Lives++;
		return true;
	}
	return false;
}

void Board::IncreaseLives() {
	Lives++;
}

void Board::DecreaseLives() {
	Lives--;
}

unsigned char Board::GetLives() {
	return Lives;
}

void Board::ScoreIncrease(unsigned short Scorer) {
	switch (Scorer) {
	case 0:
		Score += 10;
		break;
	case 1:
		Score += 50;
		break;
	default:
		Score += Scorer;
		break;
	}
}

void Board::setMapColor(MapColor _mapColor) {
	mapColor = _mapColor;
}