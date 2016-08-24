#include "Game.h"
#include "GameObjectFactory.h"

//Main Game Loop
void Execute()
{
    //Create Test Level Objects
    GameObjectFactory gameObjectFactory;

    sf::Vector2i startingPosition1 = sf::Vector2i(0, 0);
    GameObject* object = gameObjectFactory.createPlayer(startingPosition1);

    std::vector<GameObject> gameObjects;
    gameObjects.push_back(*object);

    //Variables for dealing with game objects
    World world(gameObjects);

    world.gameloop();
}
