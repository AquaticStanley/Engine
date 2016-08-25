#include "Platform.h"

void PlatformPhysicsComponent::update(GameObject & object, World & world)
{

}

void PlatformGraphicsComponent::update(GameObject & object, Graphics & graphics)
{
    graphics.draw(object.position_, object.hitbox_, sf::Color::Green);
}

void PlatformInputComponent::update(GameObject & object)
{
    
}
