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
    sf::RenderWindow window(sf::VideoMode(1200, 600), "GameWindow", sf::Style::Close);
    window.setFramerateLimit(60);

    //Variables for dealing with time and delta time
    sf::Clock deltaClock;
    double lag = 0.0;
    double lagLeftOver = 1.0;

    //Variables for tracking framerate
    sf::Clock framerateClock;
    framerateClock.restart();
    int frameCount = 0;

    //Object for graphic manipulation
    sf::RenderWindow* windowPointer = &window;
    Graphics* graphics = new Graphics(windowPointer);

    //Create Test Level
    std::vector<GameObject> gameObjects;
    CreateTestLevel(gameObjects);

    //Set background
    /*sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("background1.jpg");
    sf::Sprite backgroundSprite = sf::Sprite(backgroundTexture);
    window.draw(backgroundSprite);*/

    //Variables for dealing with game objects
    World world(gameObjects);

    //Center camera on player
    sf::View view = window.getDefaultView();
    view.setCenter(sf::Vector2f(view.getSize().x * -2, view.getSize().y) - world.entities[0].position_);

    //Set zoom
    float zoomMultiplier = 1.5;
    view.zoom(1 / zoomMultiplier);
    window.setView(view);


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

        //Track framerate
        if (framerateClock.getElapsedTime().asSeconds() >= 1)
        {
            std::cout << "FPS: " << frameCount << std::endl;
            framerateClock.restart();
            frameCount = 0;
        }
        frameCount++;

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
        //window.draw(backgroundSprite);
        world.render((lag / MS_PER_UPDATE) + (1.0 - lagLeftOver), *graphics);
        lagLeftOver = lag / MS_PER_UPDATE;

        view.setCenter(sf::Vector2f(world.entities[0].position_.x * 2, view.getSize().y * zoomMultiplier) - world.entities[0].position_);
        window.setView(view);
        window.display();

        //Display information about certain physics entity
        /*std::cout << "Object 1 Position: (" << world.entities[0].position_.x << ", " << world.entities[0].position_.y << ")\t";
        std::cout << "Object 1 Velocity: (" << world.entities[0].velocity_.x << ", " << world.entities[0].velocity_.y << ")\n";
        std::cout << std::endl;*/
    }
}

void CreateTestLevel(std::vector<GameObject>& gameObjects)
{
    //Create Test Level Objects
    GameObjectFactory gameObjectFactory;

    //Create Background

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
    sf::Vector2f startingPosition3 = sf::Vector2f(100, 200);
    sf::Vector2f hitBox2 = sf::Vector2f(3, 600);
    object = gameObjectFactory.createPlatform(startingPosition3, hitBox2);

    gameObjects.push_back(*object);

    //Create floor
    sf::Vector2f startingPosition4 = sf::Vector2f(100, 200);
    sf::Vector2f hitBox3 = sf::Vector2f(500, 5);
    object = gameObjectFactory.createPlatform(startingPosition4, hitBox3);

    gameObjects.push_back(*object);

    //Create ceiling
    sf::Vector2f startingPosition5 = sf::Vector2f(150, 250);
    sf::Vector2f hitBox4 = sf::Vector2f(300, 4);
    object = gameObjectFactory.createPlatform(startingPosition5, hitBox4);

    gameObjects.push_back(*object);

    //Create other wall
    sf::Vector2f startingPosition6 = sf::Vector2f(600, 200);
    sf::Vector2f hitBox5 = sf::Vector2f(400, 20);
    object = gameObjectFactory.createPlatform(startingPosition6, hitBox5);

    gameObjects.push_back(*object);

    //Create floor to jump to with a gap
    sf::Vector2f startingPosition7 = sf::Vector2f(1100, 200);
    sf::Vector2f hitBox6 = sf::Vector2f(400, 20);
    object = gameObjectFactory.createPlatform(startingPosition7, hitBox6);

    gameObjects.push_back(*object);
}

