#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "GameObject.h"

//Entity Dependencies
#include "Player.h"
#include "Blockman.h"
#include "Platform.h"

//Big list of constants for dimensions and characteristics
const int PLAYER_HEIGHT = 60;
const int PLAYER_WIDTH = 30;

const int BLOCKMAN_HEIGHT = 60;
const int BLOCKMAN_WIDTH = 30;


class GameObjectFactory
{
public:
	//Factory Methods
	GameObject* createPlayer(sf::Vector2i position);

	GameObject* createBlockman(sf::Vector2i position);

	//GameObject* createPlatform(sf::Vector2i position);
};

#endif