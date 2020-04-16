#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Character.h"

class Game
{
	Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	static Game* ptr_game;
	bool running;
	SDL_Renderer* renderer;
	SDL_Window* window;
	Character* dwarf;
public:
	static Game* instance();
	bool init(const char* title, const int posx, const int posy, const int width, const int height, const bool fullscreen, const bool resizable); //create window renderer
	void load(); //load texture
	void events();
	void update();
	void draw() const;
	void kill();

	bool isrunning() const;
	SDL_Renderer* getRenderer() const { return renderer; }
};

#endif
