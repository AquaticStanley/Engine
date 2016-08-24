#include "World.h"
#include <iostream>

void World::gameloop()
{
    //Variables for dealing with time and delta time
    sf::Clock deltaClock;
    double lag = 0.0;

    //Object for graphic manipulation
    Graphics* graphics = new Graphics();

    while (true)
    {
        //Get delta time
        sf::Time dt = deltaClock.restart();
        lag += dt.asMilliseconds();

        int i = 0;

        processInput();
        while (lag >= MS_PER_UPDATE)
        {
            updatePhysics();
            lag -= MS_PER_UPDATE;
        }

        render(lag / MS_PER_UPDATE, *graphics);

        std::cout << entities[0].velocity_.y << std::endl;
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

void World::resolveCollision(sf::Vector2i hitbox, sf::Vector2i& position, sf::Vector2i& velocity, const EntityType::Type type)
{
    //Check if space is occupied
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        //Check to make sure type is unique (same types move through each other)
        if (type != entities[i].type_)
        {
            //Check all four sides of given entity to entity in array
            bool x_overlap = !(position.x + hitbox.x < entities[i].position_.x ||
                               position.x > entities[i].position_.x + entities[i].hitbox_.x);


            bool y_overlap = !(position.y + hitbox.y < entities[i].position_.y ||
                               position.y > entities[i].position_.y + entities[i].hitbox_.y);


            //Handle overlaps (Beta test this, very important. If suboptimal results, implement system  which finds which direction objects need to go to separate and move 5 pixels at a time)
            if (x_overlap)
            {
                //Move back to original position
                position.x -= velocity.x;

                //Stop x-oriented movement
                velocity.x = 0;
            }

            if (y_overlap)
            {
                //Move back to original position
                position.y -= velocity.y;

                //Stop y-oriented movement
                velocity.y = 0;
            }
        }
    }
}

World::World(std::vector<GameObject> entitiesInLevel)
{
    entities = entitiesInLevel;
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