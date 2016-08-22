#include "World.h"

void World::gameloop()
{
	//Variables for dealing with time and delta time
	sf::Clock deltaClock;
	double lag = 0.0;

	//Object for graphic manipulation
	Graphics* graphics;

	while (true)
	{
		//Get delta time
		sf::Time dt = deltaClock.restart();
		lag += dt.asMilliseconds();

		processInput();

		for (int i = 0; i < entities.size; i++)
		{

		}

		while (lag >= MS_PER_UPDATE)
		{
			update();
			lag -= MS_PER_UPDATE;
		}

		render(lag/MS_PER_UPDATE);

		//Stuff
	}
}

void World::processInput()
{

}

void World::render(double frameProgress)
{

}

void World::update()
{

}