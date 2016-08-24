#include "GameObjectFactory.h"

GameObject* GameObjectFactory::createPlayer(sf::Vector2i position)
{
    return new GameObject(new PlayerInputComponent, new PlayerPhysicsComponent, new PlayerGraphicsComponent, position, sf::Vector2i(PLAYER_WIDTH, PLAYER_HEIGHT));
}

GameObject* GameObjectFactory::createBlockman(sf::Vector2i position)
{
    return nullptr;
}

//GameObject * GameObjectFactory::createPlatform(sf::Vector2f position)
//{
//	return new GameObject(new PlatformInputComponent, new PlatformPhysicsComponent, new PlatformGraphicsComponent, position);
//}
