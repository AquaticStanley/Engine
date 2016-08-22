#ifndef PLAYER_H
#define PLAYER_h

//Player class components

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"


class PlayerPhysicsComponent : public PhysicsComponent
{
public:
	virtual void update(GameObject& object, World& world);
};


class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	virtual void update(GameObject& object, Graphics& graphics);
};


class PlayerInputComponent : public InputComponent
{
public:
	virtual void update(GameObject& object);
};

#endif