#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "GameObject.h"

//Entity Dependencies
#include "Player.h"
#include "Blockman.h"
#include "Platform.h"

class GameObjectFactory
{
public:
	//Factory Methods
	GameObject* createPlayer(sf::Vector2f position);

	GameObject* createBlockman(sf::Vector2f position);

	//GameObject* createPlatform(sf::Vector2f position);
};

#endif