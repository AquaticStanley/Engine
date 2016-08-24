#include "World.h"

void World::gameloop()
{
	//Variables for dealing with time and delta time
	sf::Clock deltaClock;
	double lag = 0.0;

	//Object for graphic manipulation
	Graphics* graphics= new Graphics();

	while (true)
	{
		//Get delta time
		sf::Time dt = deltaClock.restart();
		lag += dt.asMilliseconds();

		processInput();

		while (lag >= MS_PER_UPDATE)
		{
			updatePhysics();
			lag -= MS_PER_UPDATE;
		}

		render(lag/MS_PER_UPDATE, *graphics);
	}
}

void World::processInput()
{
	//Update inputs of each entity
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities.at(i).updateInput();
	}
}

void World::render(double frameProgress, Graphics graphics)
{
	//Update graphics of each entity
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities.at(i).updateGraphics(*this, graphics, frameProgress);
	}
}

void World::resolveCollision(sf::Vector2i hitbox, sf::Vector2i& position, sf::Vector2i& velocity)
{
	//Check if space is occupied
	for (unsigned int i = 0; i < entities.size(); i++)
	{

	}
}

void World::updatePhysics()
{
	//Update physics of each entity
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		entities.at(i).updatePhysics(*this);
	}

	//Remove dead entities from array
	for (unsigned int i = 0; i < entities.size(); i++)
	{
		if (entities.at(i).toBeRemoved)
		{
			entities.erase(entities.begin() + i);
			i--;
		}
	}
}