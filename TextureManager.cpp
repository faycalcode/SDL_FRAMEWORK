#include "TextureManager.h"
#include <iostream>
#include <SDL_image.h>

using namespace std;

TextureManager* TextureManager::ptr_texturemanager = nullptr;

TextureManager* TextureManager::instance() {
	if (ptr_texturemanager == nullptr) ptr_texturemanager = new TextureManager();
	return ptr_texturemanager;
}


bool TextureManager::load(const string& file, const string& id, SDL_Renderer* renderer) {

	SDL_Surface* tmpsurface = IMG_Load(file.c_str());
	if (tmpsurface) {
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpsurface);
		SDL_FreeSurface(tmpsurface);
		if (texture) {
			textureMap[id] = texture;
			return true;
		}
	}

	cout << "Failed to load texture : " << SDL_GetError() << endl;
	return false;
}

bool TextureManager::draw(const string& id, int x, int y, int width, int height, int zoom, SDL_Renderer* renderer, SDL_RendererFlip flip) {

	SDL_Rect src;
	SDL_Rect dest;

	src.x = src.y = 0;
	dest.x = x;
	dest.y = y;
	src.w = width;
	src.h = height;
	dest.w = width * zoom;
	dest.h = height * zoom;
	if (SDL_RenderCopyEx(renderer, textureMap[id], &src, &dest, 0, NULL, flip) == 0) return true;

	cout << "Failed to draw texture : " << SDL_GetError() << endl;
	return false;
}

bool TextureManager::drawFrame(const string& id, int x, int y, int width, int height, int col, int row, int zoom, SDL_Renderer* renderer, SDL_RendererFlip flip) {

	SDL_Rect src;
	SDL_Rect dest;

	src.x = col * width;
	src.y = (row - 1) * height;
	dest.x = x;
	dest.y = y;
	src.w = width;
	src.h = height;
	dest.w = width * zoom;
	dest.h = height * zoom;

	if (SDL_RenderCopyEx(renderer, textureMap[id], &src, &dest, 0, NULL, flip) == 0) return true;

	cout << "Failed to draw texture : " << SDL_GetError() << endl;
	return false;
}