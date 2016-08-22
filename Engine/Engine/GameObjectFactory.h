#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "GameObject.h"

//Entity Dependencies
#include "Player.h"
#include "Blockman.h"

class GameObjectFactory
{
public:
	//Factory Methods
	GameObject* createPlayer();

	GameObject* createBlockman();
};

#endif