#include "GameObjectFactory.h"

GameObject* GameObjectFactory::createPlayer(sf::Vector2f position)
{
	return new GameObject(new PlayerInputComponent, new PlayerPhysicsComponent, new PlayerGraphicsComponent, position);
}

GameObject* GameObjectFactory::createBlockman(sf::Vector2f position)
{
	return new GameObject(new BlockmanInputComponent, new BlockmanPhysicsComponent, new BlockmanGraphicsComponent, position);
}

//GameObject * GameObjectFactory::createPlatform(sf::Vector2f position)
//{
//	return new GameObject(new PlatformInputComponent, new PlatformPhysicsComponent, new PlatformGraphicsComponent, position);
//}
