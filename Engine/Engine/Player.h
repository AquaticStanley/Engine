#ifndef PLAYER_H
#define PLAYER_h

//Player class components


//Dependencies
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "World.h"
#include "EntityTypes.h"

class PlayerInputComponent : public InputComponent
{
public:
    virtual void update(GameObject& object);

private:
    const int WALK_ACCELERATION = 2;
    const int IDLE_X_ACCELERATION = 2;
};

class PlayerPhysicsComponent : public PhysicsComponent
{
public:
    virtual void update(GameObject& object, World& world);

    bool isOnGround;

    PlayerPhysicsComponent() : isOnGround(false) {}
};


class PlayerGraphicsComponent : public GraphicsComponent
{
public:
    virtual void update(GameObject& object, Graphics& graphics);

    PlayerGraphicsComponent(PlayerPhysicsComponent* physics) : physics_(physics) {}

private:
    PlayerPhysicsComponent* physics_;
};

#endif