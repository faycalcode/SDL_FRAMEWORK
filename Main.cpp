#include "Game.h"

typedef Game TheGame;

int main(int argc, char** argv) {

	if (TheGame::instance()->init("SDL FRAMEWORK", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, false, true)) {
		TheGame::instance()->load();
		while (TheGame::instance()->isrunning()) {
			TheGame::instance()->events();
			TheGame::instance()->update();
			TheGame::instance()->draw();
		}
		TheGame::instance()->kill();
	}

	return 0;

}