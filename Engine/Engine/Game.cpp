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
    std::vector<GameObject> gameObjects;

    //Create Player
    sf::Vector2f startingPosition1 = sf::Vector2f(300, 600);
    GameObject* object = gameObjectFactory.createPlayer(startingPosition1);

    gameObjects.push_back(*object);

    //Create Platform
    sf::Vector2f startingPosition2 = sf::Vector2f(300, 500);
    sf::Vector2f hitBox1 = sf::Vector2f(10, 3);
    object = gameObjectFactory.createPlatform(startingPosition2, hitBox1);

    gameObjects.push_back(*object);

    //Create wall
    sf::Vector2f startingPosition3 = sf::Vector2f(100, 500);
    sf::Vector2f hitBox2 = sf::Vector2f(3, 20);
    object = gameObjectFactory.createPlatform(startingPosition3, hitBox2);

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

        //Display information about certain physics entity
        std::cout << "Object 1 Position: (" << world.entities[0].position_.x << ", " << world.entities[0].position_.y << ")\t";
        std::cout << "Object 1 Velocity: (" << world.entities[0].velocity_.x << ", " << world.entities[0].velocity_.y << ")\n";
        std::cout << "Object 2 Position: (" << world.entities[1].position_.x << ", " << world.entities[1].position_.y << ")\t";
        std::cout << "Object 2 Velocity: (" << world.entities[1].velocity_.x << ", " << world.entities[1].velocity_.y << ")\n\n";
        std::cout << std::endl;

        //i++;
    }
}

