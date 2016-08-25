#ifndef PLATFORM_H
#define PLATFORM_H

//Platform class components

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "World.h"

class PlatformPhysicsComponent : public PhysicsComponent
{
public:
    virtual void update(GameObject& object, World& world);
};

class PlatformGraphicsComponent : public GraphicsComponent
{
public:
    virtual void update(GameObject& object, Graphics& graphics);

    PlatformGraphicsComponent(PlatformPhysicsComponent* physics) : physics_(physics) {}

private:
    PlatformPhysicsComponent* physics_;
};

class PlatformInputComponent : public InputComponent
{
public:
    virtual void update(GameObject& object);
};

#endif