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
	}
	mapTexture->setColor(color);
}
void Map::draw(SDL_Renderer* renderer) {
	mapTexture->render(renderer);
}

void Map::loadNumericMap() {
	for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
			switch (charMap[i * TOTAL_BLOCK_X + j]) {
				case '#':
					numericMap[i][j] = WALL;
					break;
				case '=':
					numericMap[i][j] = DOOR;
					break;
				case '.':
					numericMap[i][j] = PELLET;
					break;
				case 'o':
					numericMap[i][j] = ENERGIZER;
					break;
				default:
					numericMap[i][j] = NOTHING;
					break;
			}
		}
		
	}
	/*for (int i = 0; i < TOTAL_BLOCK_Y; i++) {
		for (int j = 0; j < TOTAL_BLOCK_X; j++) {
			std::cout << numericMap[i][j] << " ";
		}
		std::cout << std::endl;
	}*/


}