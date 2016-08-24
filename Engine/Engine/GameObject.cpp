#include "GameObject.h"

//Note: This is the file where all create(objects) are held.

void GameObject::updateInput()
{
    input_->update(*this);
}

void GameObject::updatePhysics(World & world)
{
    physics_->update(*this, world);
}

void GameObject::updateGraphics(World & world, Graphics & graphics, double frameProgress)
{
    graphics_->update(*this, graphics);
}
