#ifndef WORLD_H
#define WORLD_H

//Dependencies
#include <SFML\System\Clock.hpp>
#include "Graphics.h"
#include "GameObject.h"
#include <vector>
#include "MathFunctions.h"

//Constants
const float MS_PER_UPDATE = 10.0;

const int MAX_ENTITIES = 3000;

const float WORLD_X_SPEED_LIMIT = 2.5;

const float WORLD_Y_SPEED_LIMIT = 10;

const float WORLD_GRAVITY_ACCELERATION = -0.05;

//Class definition
class World
{
public:
    void processInput();

    void updatePhysics();

    void render(double frameProgress, Graphics graphics);

    void resolveCollision(const sf::Vector2f& hitbox, sf::Vector2f& position, sf::Vector2f
        & velocity, const EntityType::Type type, bool& isOnGround);

    World(std::vector<GameObject> entitiesInLevel);

    std::vector<GameObject> entities;
};

#endif