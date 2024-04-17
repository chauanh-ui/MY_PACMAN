#include "Map.h"

Map::Map(SDL_Renderer* renderer) {
	mapTexture = new Texture(IMAGE_MAP_PATH, IMAGE_MAP_SRC, IMAGE_MAP_DST, renderer);
}

void Map::draw(SDL_Renderer* renderer) {
	mapTexture->setColor(0, 0, 255);
	mapTexture->render(renderer);
}