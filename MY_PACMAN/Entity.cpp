#include "Entity.h"

Entity::Entity(SDL_Renderer* renderer, const int _entityType) {
	std::string imagePath = "";
	switch (entityType)
	{
	case PACMAN:
		src = PACMAN_IMAGE_SRC;
		container = PACMAN_IMAGE_CONTAINER;
		imagePath = PACMAN_IMAGE_PATH;
		speed = 10;
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

void Entity::checkCollisionWithWalls() {
	;
}

void Entity::move(SDL_Event& e) {
	if (e.key.keysym.sym == SDLK_UP && turnAllows[DIRECTION_UP]) {
		container.y -= speed;
		if (container.y < 0) {
			container.y = 0;
		}
	}
	else if (e.key.keysym.sym == SDLK_DOWN && turnAllows[DIRECTION_DOWN]) {
		container.y += speed;
		if (container.y + container.h > WINDOW_HEIGHT) {
			container.y = WINDOW_HEIGHT - container.h;
		}
	}
	else if (e.key.keysym.sym == SDLK_LEFT && turnAllows[DIRECTION_LEFT]) {
		container.x -= speed;
		if (container.x < 0) {
			container.x = 0;
		}
	}
	else if (e.key.keysym.sym == SDLK_RIGHT && turnAllows[DIRECTION_RIGHT]) {
		container.x += speed;
		if (container.x + container.w > WINDOW_WIDTH) {
			container.x = WINDOW_WIDTH - container.w;
		}
	}
}

