#include "Player.h"

void PlayerInputComponent::update(GameObject & object)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (physics_->isOnGround)
        {
            object.velocity_.x += WALK_ACCELERATION_GROUND;
        }
        else
        {
            object.velocity_.x += WALK_ACCELERATION_AIR;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (physics_->isOnGround)
        {
            object.velocity_.x -= WALK_ACCELERATION_GROUND;
        }
        else
        {
            object.velocity_.x -= WALK_ACCELERATION_AIR;
        }
    }
    //Neither right nor left are held down
    else
    {
        //Get direction of velocity
        if (object.velocity_.x > .5)
        {
            if (physics_->isOnGround)
            {
                object.velocity_.x -= IDLE_X_ACCELERATION_GROUND;
            }
            else
            {
                object.velocity_.x -= IDLE_X_ACCELERATION_AIR;
            }
        }
        else if (object.velocity_.x < -.5)
        {
            if (physics_->isOnGround)
            {
                object.velocity_.x += IDLE_X_ACCELERATION_GROUND;
            }
            else
            {
                object.velocity_.x += IDLE_X_ACCELERATION_AIR;
            }
        }
        //Velocity is between -.5 and .5
        else
        {
            object.velocity_.x = 0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && physics_->isOnGround)
    {
        object.velocity_.y += JUMP_VELOCITY;
        physics_->isOnGround = false;
    }
}

void PlayerPhysicsComponent::update(GameObject& object, World& world)
{
    //Set Player's velocity due to acceleration from gravity
    if (!isOnGround)
    {
        object.velocity_.y += WORLD_GRAVITY_ACCELERATION;
    }
    else
    {
        object.velocity_.y = 0;
    }

    //Cap x and y movement speeds from world speed limits
    if (abs(object.velocity_.x) >= WORLD_X_SPEED_LIMIT)
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

    if (abs(object.velocity_.y) >= WORLD_Y_SPEED_LIMIT)
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

    //Set Player's position due to velocity (Optimization)
    object.position_ += object.velocity_;

    //Resolve world collisions
    world.resolveCollision(object.hitbox_, object.position_, object.velocity_, object.type_, isOnGround);
}

void PlayerGraphicsComponent::update(GameObject & object, Graphics & graphics, double frameProgress)
{
    sf::Vector2f predictedPosition = object.position_ + sf::Vector2f(object.velocity_.x * frameProgress, object.velocity_.y * frameProgress);

    graphics.draw(predictedPosition, object.hitbox_, STANDING_SPRITE);
}

