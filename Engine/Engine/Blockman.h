#ifndef BLOCKMAN_H
#define BLOCKMAN_H

//Player class components

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"


class BlockmanPhysicsComponent : public PhysicsComponent
{
public:
	virtual void update(GameObject& object, World& world);
};


class BlockmanGraphicsComponent : public GraphicsComponent
{
public:
	virtual void update(GameObject& object, Graphics& graphics);
};


class BlockmanInputComponent : public InputComponent
{
public:
	virtual void update(GameObject& object);
};

#endif