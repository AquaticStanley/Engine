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
	sf::Vector2i position_;
	sf::Vector2i velocity_;
	sf::Vector2i hitbox_;

	//Variable describing if object should be removed on next frame
	bool toBeRemoved;

	GameObject(InputComponent* input, 
			   PhysicsComponent* physics, 
			   GraphicsComponent* graphics,
			   sf::Vector2i position,
			   sf::Vector2i hitbox)
		: input_(input), physics_(physics), graphics_(graphics), position_(position), velocity_(0, 0), hitbox_(hitbox) {
		toBeRemoved = false;
	}

	void updateInput();

	void updatePhysics(World& world);

	void updateGraphics(World& world, Graphics& graphics, double frameProgress);

private:
	InputComponent* input_;
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};

class InputComponent;
class PhysicsComponent;
class GraphicsComponent;

#endif