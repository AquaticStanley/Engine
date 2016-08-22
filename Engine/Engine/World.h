#ifndef WORLD_H
#define WORLD_H

//Dependencies
#include <SFML\System\Clock.hpp>
#include "Graphics.h"
#include "GameObject.h"
#include <vector>

//Constants
const int MS_PER_UPDATE = 10;

const int MAX_ENTITIES = 3000;

//Class definition
class World
{
public:
	void gameloop();

	void processInput();

	void updatePhysics();

	void render(double frameProgress, Graphics graphics);

private:
	std::vector<GameObject> entities;
};

#endif