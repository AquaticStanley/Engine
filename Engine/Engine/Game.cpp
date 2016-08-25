#include "Game.h"
#include "GameObjectFactory.h"
#include <iostream>
#include <SFML\System\Clock.hpp>
#include "Graphics.h"
#include "GameObject.h"
#include <vector>
#include "MathFunctions.h"

//Main Game Loop
void Execute()
{
    //SFML Window Initialization
    sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow", sf::Style::Close);
    window.setFramerateLimit(60);

    //Variables for dealing with time and delta time
    sf::Clock deltaClock;
    double lag = 0.0;

    //Object for graphic manipulation
    sf::RenderWindow* windowPointer = &window;
    Graphics* graphics = new Graphics(windowPointer);

    //Create Test Level Objects
    GameObjectFactory gameObjectFactory;

    sf::Vector2f startingPosition1 = sf::Vector2f(0, 600);
    GameObject* object = gameObjectFactory.createPlayer(startingPosition1);
    //
    //sf::Vector2f startingPosition2 = sf::Vector2f(0, 596);
    //sf::Vector2f platformHitbox = sf::Vector2f(300, 2);
    //GameObject* object2 = gameObjectFactory.createPlatform(startingPosition2, platformHitbox);

    std::vector<GameObject> gameObjects;
    gameObjects.push_back(*object);
    //gameObjects.push_back(*object2);

    //Variables for dealing with game objects
    World world(gameObjects);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Close requested
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        ////Measure FPS
        //static sf::Clock fpsTimer;
        //static int i = 0;
        //if (fpsTimer.getElapsedTime() >= sf::seconds(1))
        //{
        //    std::cout << i << std::endl;
        //    i = 0;
        //    fpsTimer.restart();
        //}

        //Get delta time
        sf::Time dt = deltaClock.restart();
        lag += dt.asMilliseconds();

        world.processInput();

        while (lag >= MS_PER_UPDATE)
        {
            world.updatePhysics();
            lag -= MS_PER_UPDATE;
        }

        world.render(lag / MS_PER_UPDATE, *graphics);

        window.display();

        std::cout << world.entities[0].velocity_.y << std::endl;

        //i++;
    }
}

