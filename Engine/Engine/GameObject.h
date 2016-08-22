#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML\System\Vector2.hpp>
#include "Graphics.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"
#include "InputComponent.h"

class World;

class GameObject
{
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	bool toBeRemoved = false;

	GameObject(InputComponent* input, 
			   PhysicsComponent* physics, 
			   GraphicsComponent* graphics)
		: input_(input), physics_(physics), graphics_(graphics){}

	void update(World& world, Graphics& graphics);

private:
	InputComponent* input_;
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};

class InputComponent;
class PhysicsComponent;
class GraphicsComponent;

#endif