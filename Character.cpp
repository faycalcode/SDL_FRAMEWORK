#include "Character.h"
#include "TextureManager.h"
#include "Game.h"

typedef TextureManager TheTextureManager;
typedef Game TheGame;

Character::Character(const LoaderParams& params):GameObject(params){
    m_x = params.getx();
    m_y = params.gety();
    m_width = params.getwidth();
    m_height = params.getheight();
    m_id = params.getid();
    m_zoom = params.getzoom();

    TheTextureManager::instance()->load(params.getfile(), m_id,TheGame::instance()->getRenderer());
}

void Character::update() {

}

void Character::draw() const {

    int col = int(SDL_GetTicks()/100) % 5;
    TheTextureManager::instance()->drawFrame(m_id, m_x, m_y, m_width, m_height, col, 1, m_zoom, TheGame::instance()->getRenderer());

}

void Character::kill() {

}