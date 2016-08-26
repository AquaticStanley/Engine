#ifndef GRAPHICS_H
#define GRAPHICS_H

//This class interacts with SFML as a wrapper and high level interpreter for sprite and graphic manipulation

#include "SFML\Graphics\Sprite.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window\Window.hpp"

class Graphics
{
public:
    Graphics(sf::RenderWindow* window) : window_(window) {}

    void draw(int x, int y);

    void draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Color color);

    void draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Sprite sprite);

    void translatePosition(sf::Vector2f& position, sf::RenderWindow * window);

private:
    sf::RenderWindow* window_;
};

#endif