#include <iostream>
#include "Game.h"

using namespace std;

Game* Game::ptr_game = nullptr;

Game::Game(){
	window = nullptr;
	renderer = nullptr;
	running = false;
	dwarf = nullptr;
}

Game* Game::instance() {
	if (ptr_game == nullptr) ptr_game = new Game();
	return ptr_game;
}

bool Game::init(const char* title, const int posx, const int posy, const int width, const int height, const bool fullscreen, const bool resizable) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		int flags = 0;
		if (fullscreen) flags |= SDL_WINDOW_FULLSCREEN;
		if (resizable) flags |= SDL_WINDOW_RESIZABLE;

		window = SDL_CreateWindow(title, posx, posy, width, height, flags);
		if (window != nullptr) {

			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			if (SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255) == 0) {
				running = true;
				return true;
			}
			else {
				cout << "Failed to set color : " << SDL_GetError() << endl;
				return false;
			}
		}
		else {
			cout << "Failed to create window : " << SDL_GetError() << endl;
			return false;
		}

	}
	else {
		cout << "Failed to initialize SDL" << SDL_GetError() << endl;
		return false;
	}
}

void Game::load() {

	dwarf = new Character(LoaderParams(10, 10, 38, 38, 10, "assets/dwarf-ss.png", "dwarf"));

}

void Game::events() {

	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
	}

}

void Game::update() {
	dwarf->update();
}

void Game::draw() const {

	SDL_RenderClear(renderer);

	dwarf->draw();

	SDL_RenderPresent(renderer);

}

void Game::kill() {
	running = false;
	dwarf->kill();
	delete dwarf;
	cout << "Exiting the game" << endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isrunning() const {
	return running;
}