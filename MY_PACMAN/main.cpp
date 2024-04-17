
#include"GameObject.h"

int main(int argc, char* argv[]) {
	GameObject* game = new GameObject;
	game->initialize();
	game->running();
	//game->renderGame();
	waitUntilKeyPressed();
	std::cout << "SUCCESS!\n";
	delete game;
	return 0;
}