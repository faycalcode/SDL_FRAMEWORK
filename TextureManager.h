#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <map>
#include <string>

class TextureManager
{
	TextureManager() = default;
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	static TextureManager* ptr_texturemanager;
	std::map<std::string, SDL_Texture*> textureMap;
public:

	static TextureManager* instance();
	bool load(const std::string& file, const std::string& id, SDL_Renderer* renderer);
	bool draw(const std::string& id, int x, int y, int width, int height, int zoom, SDL_Renderer*, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool drawFrame(const std::string& id, int x, int y, int width, int height, int col, int row, int zoom, SDL_Renderer*, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif // !TEXTUREMANAGER_H