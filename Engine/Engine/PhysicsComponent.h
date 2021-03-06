#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

//Dependencies
#include "Dimensions.h"

class GameObject;
class World;

class PhysicsComponent
{
public:
    virtual void update(GameObject& object, World& world) = 0;
};


#endif