#include "Graphics.h"

//Note: Current version of this function results in a flipped position
void Graphics::draw(int x, int y)
{
    sf::CircleShape circle = sf::CircleShape(10, 30);
    circle.setFillColor(sf::Color::Green);
    
    circle.setPosition(x, y);

    window_->draw(circle);
    return;
}

void Graphics::draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Color color)
{
    sf::RectangleShape rectangle = sf::RectangleShape(hitbox);
    rectangle.setOrigin(0, rectangle.getSize().y);
    rectangle.setFillColor(color);

    //Translate position
    translatePosition(position, window_);

    rectangle.setPosition(position);

    window_->draw(rectangle);
    return;
}

void Graphics::translatePosition(sf::Vector2f& position, sf::RenderWindow* window)
{
    position.y = window->getSize().y - position.y;
    return;
}