#include "Platform.h"

void PlatformPhysicsComponent::update(GameObject & object, World & world)
{
    bool dummy = true;
    //world.resolveCollision(object.hitbox_, object.position_, object.velocity_, object.type_, dummy);
}

void PlatformGraphicsComponent::update(GameObject & object, Graphics & graphics, double frameProgress)
{
    graphics.draw(object.position_, object.hitbox_, sf::Color::Green);
}

void PlatformInputComponent::update(GameObject & object)
{
    
}
