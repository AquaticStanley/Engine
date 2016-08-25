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
    

    std::vector<GameObject> gameObjects;
    gameObjects.push_back(*object);

    //Variables for dealing with game objects
    World world(gameObjects);

    //First time render
    window.clear(sf::Color::Black);
    world.render(1.0, *graphics);
    window.display();
    
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

        //Get delta time
        sf::Time dt = deltaClock.restart();
        lag += dt.asMilliseconds();

        world.processInput();

        while (lag >= MS_PER_UPDATE)
        {
            world.updatePhysics();
            lag -= MS_PER_UPDATE;
        }


        window.clear(sf::Color::Black);
        world.render(lag / MS_PER_UPDATE, *graphics);
        window.display();

        std::cout << world.entities[0].velocity_.x << std::endl;

        //i++;
    }
}

