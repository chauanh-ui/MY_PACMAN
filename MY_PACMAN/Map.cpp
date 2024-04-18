#include "Map.h"


Map::Map(SDL_Renderer* renderer) {
	mapTexture = new Texture(IMAGE_MAP_PATH, IMAGE_MAP_SRC, IMAGE_MAP_DST, renderer);
	loadNumericMap();
}

void Map::changeMapColor(SDL_Event& e) {
	SDL_Color color = { 255, 255, 255 };
	switch (e.key.keysym.sym)
	{
	case SDLK_1: 
		color = GREEN;
		break;
	case SDLK_2:
		color = BLUE;
		break;
	case SDLK_3:
		color = PINK;
		break;
	case SDLK_4:
		color = PURPLE;
		break;
	default:
		break;
	}
	mapTexture->setColor(color);
}
void Map::draw(SDL_Renderer* renderer) {
	mapTexture->render(renderer);
}

void Map::loadNumericMap() {
	for (unsigned short i = 0; i < TOTAL_BLOCK_Y * TOTAL_BLOCK_X; i++) {
		switch (charMap[i]) {
		case '#':
			numericMap[i] = WALL;
			break;
		case '=':
			numericMap[i] = DOOR;
			break;
		case '.':
			numericMap[i] = PELLET;
			break;
		case 'o':
			numericMap[i] = ENERGIZER;
			break;
		default:
			numericMap[i] = NOTHING;
			break;
		}
	}
	/*for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
			std::cout << (int) numericMap[i * TOTAL_BLOCK_X + j] << " ";
		}
		std::cout << std::endl;
	}*/


}