#pragma once

#include "entities/enemies/Enemy.h"

/**
 * Zombie is one of the enemy types, he isn't particulary strength but he is speeder
 *
 * @author Amélie Guédès (MelyMelo8)
 * @version 0.1
 */
class Zombie : public Enemy{
public:
    /**
     * Create new Zombie
     * @param xPos, yPos position of the Entity
     */
    Zombie(uint16_t xPos, uint16_t yPos);

};

