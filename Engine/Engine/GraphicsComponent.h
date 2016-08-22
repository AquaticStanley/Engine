#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "Graphics.h"

class GameObject;

class GraphicsComponent
{
public:
	virtual void update(GameObject& object, Graphics& graphics) = 0;
};

#endif