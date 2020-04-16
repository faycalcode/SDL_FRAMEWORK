#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameObject.h"

class Character : public GameObject
{
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_zoom;
	std::string m_id;
public:
	Character(const LoaderParams&);
	void update();
	void draw() const;
	void kill();
};

#endif // !CHARACTER_H