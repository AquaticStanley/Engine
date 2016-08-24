#include "Player.h"

void PlayerInputComponent::update(GameObject & object)
{

}

void PlayerPhysicsComponent::update(GameObject& object, World& world)
{
    //object.position_.x += object.velocity_.x;
    //object.position_.y += object.velocity_.y;

    //Set object's position due to velocity (Optimization)
    object.position_ += object.velocity_;

    //Resolve world collisions
    world.resolveCollision(object.hitbox_, object.position_, object.velocity_);
}

void PlayerGraphicsComponent::update(GameObject & object, Graphics & graphics)
{

}
