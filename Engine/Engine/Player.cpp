#include "Player.h"

void PlayerInputComponent::update(GameObject & object)
{

}

void PlayerPhysicsComponent::update(GameObject& object, World& world)
{
	//object.position_.x += object.velocity_.x;
	//object.position_.y += object.velocity_.y;

	//Optimization
	object.position_ += object.velocity_;
}

void PlayerGraphicsComponent::update(GameObject & object, Graphics & graphics)
{

}
