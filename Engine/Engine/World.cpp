#include "World.h"
#include <iostream>


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

void World::resolveCollision(const sf::Vector2f& hitbox, sf::Vector2f& position, sf::Vector2f& velocity, const EntityType::Type type, bool& isOnGround)
{
    sf::Vector2f previousPosition = position - velocity;

    //Check if space is occupied
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        //Check to make sure type is unique (same types move through each other)
        //Later on, change to also check if entity being examined is the same entity that is being passed in
        if (type != entities[i].type_)
        {
            //Handle overlaps (Beta test this, very important. If suboptimal results, implement system  which finds which direction objects need to go to separate and move 5 pixels at a time)
            bool sameXLevel = valueInRange(entities[i].position_.x, position.x, position.x + hitbox.x) ||
                valueInRange(position.x, entities[i].position_.x, entities[i].position_.x + entities[i].hitbox_.x);

            bool sameYLevel = valueInRange(entities[i].position_.y, position.y, position.y + hitbox.y) ||
                valueInRange(position.y, entities[i].position_.y, entities[i].position_.y + entities[i].hitbox_.y);

            if (sameXLevel && sameYLevel)
            {
                //Collision Detected!
                if (previousPosition.y > entities[i].position_.y + entities[i].hitbox_.y)
                {
                    //Was above object before collision

                    //Move up until no collision
                    while (position.y <= entities[i].position_.y + entities[i].hitbox_.y)
                    {
                        position.y++;
                    }

                    //Stop pushing into object
                    velocity.y = 0;

                    isOnGround = true;

                }
                else if (previousPosition.y + hitbox.y < entities[i].position_.y)
                {
                    //Was below object before collision

                    //Move down until no collision
                    while (position.y + hitbox.y >= entities[i].position_.y)
                    {
                        position.y--;
                    }

                    //Stop pushing into object
                    velocity.y = 0;
                }
                else
                {
                    //Was same level as object before collision - Horizontal collision detected
                    if (previousPosition.x > entities[i].position_.x + entities[i].hitbox_.x)
                    {
                        //Was to the right of object before collision

                        //Move to the right until no collision
                        while (position.x <= entities[i].position_.x + entities[i].hitbox_.x)
                        {
                            position.x++;
                        }

                        //Stop pushing into object
                        velocity.x = 0;
                    }
                    else if (previousPosition.x + hitbox.x < entities[i].position_.x)
                    {
                        //Was to the left of object before collision

                        //Move to the left until no collision
                        while (position.x + hitbox.x >= entities[i].position_.x)
                        {
                            position.x--;
                        }

                        //Stop pushing into object
                        velocity.x = 0;
                    }
                }


                //if (sameYLevel)
                //{
                //    //Specified object's right side is clipping into left side of foreign object
                //    if (!(position.x + hitbox.x < entities[i].position_.x))
                //    {
                //        //Move to the left;
                //        position.x--;

                //        //Stop pushing into object
                //        velocity.x = 0;
                //    }
                //    //Specified object's left side is clipping into right side of foreign object
                //    else if (!(position.x > entities[i].position_.x + entities[i].hitbox_.x))
                //    {
                //        //Move to the right
                //        position.x++;

                //        //Stop pushing into object
                //        velocity.x = 0;
                //    }
                //}

                //if (sameXLevel)
                //{
                //    //Specified object's top side is clipping into bottom side of foreign object
                //    if (!(position.y + hitbox.y < entities[i].position_.y))
                //    {
                //        //Stop pushing into object
                //        velocity.y = 0;
                //    }
                //    //Specified object's bottom side is clipping into top side of foreign object
                //    else if (!(position.y > entities[i].position_.y + entities[i].hitbox_.y))
                //    {
                //        //Move up
                //        position.y++;

                //        //Stop pushing into object
                //        velocity.y = 0;

                //        isOnGround = true;
                //    }
                //}
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