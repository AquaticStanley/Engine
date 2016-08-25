#include "Player.h"

void PlayerInputComponent::update(GameObject & object)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        object.velocity_.x += WALK_ACCELERATION;
        
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        object.velocity_.x -= WALK_ACCELERATION;
    }
    //Neither right nor left are held down
    else
    {
        //Get direction of velocity
        if (object.velocity_.x > 2)
        {
            object.velocity_.x -= IDLE_X_ACCELERATION;
        }
        else if (object.velocity_.x < -2)
        {
            object.velocity_.x += IDLE_X_ACCELERATION;
        }
        //Velocity is between -2 and 2
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
    //object.position_.x += object.velocity_.x;
    //object.position_.y += object.velocity_.y;

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

void PlayerGraphicsComponent::update(GameObject & object, Graphics & graphics)
{
    graphics.draw(object.position_, object.hitbox_, sf::Color::Blue);
}

