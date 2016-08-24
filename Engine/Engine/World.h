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

const int WORLD_X_SPEED_LIMIT = 30;

const int WORLD_Y_SPEED_LIMIT = 30;

//Class definition
class World
{
public:
	void gameloop();

	void processInput();

	void updatePhysics();

	void render(double frameProgress, Graphics graphics);

	void resolveCollision(sf::Vector2i hitbox, sf::Vector2i& position, sf::Vector2i& velocity);

private:
	std::vector<GameObject> entities;
};

#endif