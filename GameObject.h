#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"

class GameObject
{
public:
	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual void kill() = 0;
protected:
	GameObject(const LoaderParams& params) {}
	~GameObject() {}
};

#endif // !GAMEOBJECT_H