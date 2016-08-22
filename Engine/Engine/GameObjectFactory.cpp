#include "GameObjectFactory.h"

GameObject* GameObjectFactory::createPlayer()
{
	return new GameObject(new PlayerInputComponent, new PlayerPhysicsComponent, new PlayerGraphicsComponent);
}

GameObject* GameObjectFactory::createBlockman()
{
	return new GameObject(new BlockmanInputComponent, new BlockmanPhysicsComponent, new BlockmanGraphicsComponent);
}
