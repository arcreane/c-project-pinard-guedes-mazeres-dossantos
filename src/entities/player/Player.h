#pragma once

#include "entities/Bullet.h"
#include "entities/Entity.h"

#define IMG_PATH "assets/player.png"

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
    Player(uint16_t xPos, uint16_t yPos, float speed);

    Player(uint16_t xPos, uint16_t yPos, float speed, Texture2D textureForBullets, float delay);

    ~Player();
    void Event();
    void Update();
    void Draw();

private:
    float speed;
    Bullet* bullets;
    int maxBullets;
    float shootingTimer;
    float shootingDelay;
};

#endif