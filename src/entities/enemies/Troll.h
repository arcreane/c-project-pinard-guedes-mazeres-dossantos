#pragma one

#include "entities/enemies/Enemy.h"

/**
 * Troll is one of the enemy types, he is particulary strength but he is slower
 *
 * @author Amélie Guédès (MelyMelo8)
 * @version 0.1
 */
class Troll : public Enemy{
public:

    /**
     * Create a new Troll
     * @param xPos, yPos position of the Entity
     */
    Troll(uint16_t xPos, uint16_t yPos);

};

