#include "GameObjectFactory.h"

GameObject* GameObjectFactory::createPlayer(sf::Vector2i position)
{
    PlayerPhysicsComponent* physics = new PlayerPhysicsComponent;
    return new GameObject(new PlayerInputComponent, physics, new PlayerGraphicsComponent(physics), position, sf::Vector2i(PLAYER_WIDTH, PLAYER_HEIGHT), EntityType::Player);
}

GameObject* GameObjectFactory::createBlockman(sf::Vector2i position)
{
    return nullptr;
}

//GameObject * GameObjectFactory::createPlatform(sf::Vector2f position)
//{
//	return new GameObject(new PlatformInputComponent, new PlatformPhysicsComponent, new PlatformGraphicsComponent, position);
//}
