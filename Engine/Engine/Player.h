#ifndef PLAYER_H
#define PLAYER_h

//Player class components


//Dependencies
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "World.h"

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

private:
	const int WALK_ACCELERATION = 1;
};

#endif