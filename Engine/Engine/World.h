#ifndef WORLD_H
#define WORLD_H

//Dependencies
#include <SFML\System\Clock.hpp>
#include "Graphics.h"
#include "GameObject.h"
#include <list>

//Constants
const int MS_PER_UPDATE = 10;

const int MAX_ENTITIES = 3000;

//Class definition
class World
{
public:
	void gameloop();

	void processInput();

	void update();

	void render(double frameProgress);

private:
	std::list<GameObject> entities;
};

#endif