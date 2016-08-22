#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "World.h"

class GameObject;

class PhysicsComponent
{
public:
	virtual void update(GameObject& object, World& world) = 0;
};


#endif