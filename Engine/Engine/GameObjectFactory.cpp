#include "GameObjectFactory.h"

GameObject* GameObjectFactory::createPlayer(sf::Vector2f position)
{
    PlayerPhysicsComponent* physics = new PlayerPhysicsComponent;
    return new GameObject(new PlayerInputComponent, physics, new PlayerGraphicsComponent(physics), position, sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT), EntityType::Player);
}

GameObject* GameObjectFactory::createBlockman(sf::Vector2f position)
{
    return nullptr;
}

GameObject* GameObjectFactory::createPlatform(sf::Vector2f position, sf::Vector2f hitbox)
{
    PlatformPhysicsComponent* physics = new PlatformPhysicsComponent;
    return new GameObject(new PlatformInputComponent, physics, new PlatformGraphicsComponent(physics), position, hitbox, EntityType::Object);
}