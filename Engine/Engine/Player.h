#ifndef PLAYER_H
#define PLAYER_h

//Player class components


//Dependencies
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "World.h"
#include "EntityTypes.h"

class PlayerPhysicsComponent : public PhysicsComponent
{
public:
    virtual void update(GameObject& object, World& world);

    bool isOnGround;

    PlayerPhysicsComponent() : isOnGround(false) {}
};


class PlayerInputComponent : public InputComponent
{
public:
    virtual void update(GameObject& object);

    PlayerInputComponent(PlayerPhysicsComponent* physics) : physics_(physics) {}

private:
    const int WALK_ACCELERATION = 1;
    const int IDLE_X_ACCELERATION = 1;
    const int JUMP_VELOCITY = 10;

    PlayerPhysicsComponent* physics_;
};


class PlayerGraphicsComponent : public GraphicsComponent
{
public:
    virtual void update(GameObject& object, Graphics& graphics);

    PlayerGraphicsComponent(PlayerPhysicsComponent* physics) : physics_(physics)
    {
        bool loaded=STANDING_TEXTURE.loadFromFile("grillStandingSprite.png");

        STANDING_SPRITE.setTexture(STANDING_TEXTURE);
        STANDING_SPRITE.setTextureRect(sf::IntRect(0, 0, 15, 30));
        
    }



private:
    PlayerPhysicsComponent* physics_;
    sf::Texture STANDING_TEXTURE;
    sf::Sprite STANDING_SPRITE;
};

#endif