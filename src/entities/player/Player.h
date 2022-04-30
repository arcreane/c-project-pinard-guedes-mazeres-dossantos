#pragma once

#include "entities/Bullet.h"
#include "entities/Entity.h"

#ifndef _PLAYER_
#define _PLAYER_

/**
 * The Window class encapsulates the existence of a window, and defines a
 * simplified interface between the application and the raylib API.
 *
 * @author Nicolas Dos Santos / Alexander Mazeres
 * @version 0.1
 */

class Player : public Entity{
public:

    /**
     * Create a new Player
     * @param xPos, yPos position for the Entity
     * @param speed
     */
    Player(uint16_t xPos, uint16_t yPos, float speed);

    /**
     * Create a new Player
     * @param xPos, yPos position for the Entity
     * @param speed
     * @param delay
     */
    Player(uint16_t xPos, uint16_t yPos, float speed, float delay);

    /**
     * Destructor for Player, unloads the bullets and the sprite texture from GPU.
     */
    ~Player() override;

    /**
     * Capte the user keys for moving the player or shoot a bullet
     */
    void event();

    /**
     * ??
     */
    void draw();

    /**
     * Update the Player
     * @return <code>false</code> if the entity should be discarded from the
     * scene, <code>true</code> otherwise
     */
    bool update() override;

private:
    float speed;
    Bullet* bullets;
    int maxBullets;
    float shootingTimer;
    float shootingDelay;
};

#endif