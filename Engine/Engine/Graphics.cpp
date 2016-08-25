#include "Graphics.h"

void Graphics::draw(int x, int y)
{
    sf::CircleShape circle = sf::CircleShape(10, 30);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(x, y);

    window_->draw(circle);
}

void Graphics::draw(sf::Vector2f position, sf::Vector2f hitbox, sf::Color color)
{
    sf::RectangleShape rectangle = sf::RectangleShape(hitbox);
    rectangle.setOrigin(0, rectangle.getSize().y);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);

    window_->draw(rectangle);
}
