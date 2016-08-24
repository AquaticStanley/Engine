#ifndef PLATFORM_H
#define PLATFORM_H

//Platform class components

#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"

class PlatformPhysicsComponent : public PhysicsComponent
{
public:
    virtual void update(GameObject& object, World& world);
};

class PlatformGraphicsComponent : public GraphicsComponent
{
public:
    virtual void update(GameObject& object, Graphics& graphics);
};

class PlatformInputComponent : public GraphicsComponent
{
public:
    virtual void update(GameObject& object);
};

#endif