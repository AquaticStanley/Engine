#include "GameObject.h"

//Note: This is the file where all create(objects) are held.

void GameObject::update(World& world, Graphics& graphics)
{
	input_->update(*this);
	physics_->update(*this, world);
	graphics_->update(*this, graphics);
}