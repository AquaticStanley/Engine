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

    //Set object's velocity due to acceleration from gravity
    if (!isOnGround)
    {
        object.velocity_.y += WORLD_GRAVITY_ACCELERATION;
    }


    //Cap x and y movement speeds from world speed limits
    if (abs(object.velocity_.x) > WORLD_X_SPEED_LIMIT)
    {
        if (object.velocity_.x < 0)
        {
            object.velocity_.x = WORLD_X_SPEED_LIMIT*-1;
        }
        else
        {
            object.velocity_.x = WORLD_X_SPEED_LIMIT;
        }
    }

    if (abs(object.velocity_.y) > WORLD_Y_SPEED_LIMIT)
    {
        if (object.velocity_.y < 0)
        {
            object.velocity_.y = WORLD_Y_SPEED_LIMIT*-1;
        }
        else
        {
            object.velocity_.y = WORLD_Y_SPEED_LIMIT;
        }
    }


    //Resolve world collisions
    world.resolveCollision(object.hitbox_, object.position_, object.velocity_, object.type_);
}

void PlayerGraphicsComponent::update(GameObject & object, Graphics & graphics)
{

}
