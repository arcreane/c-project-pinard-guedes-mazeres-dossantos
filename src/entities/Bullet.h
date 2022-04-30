#include "entities/Entity.h"

#ifndef _BULLET_
#define _BULLET_

/**
 * The Window class encapsulates the existence of a window, and defines a
 * simplified interface between the application and the raylib API.
 *
 * @author Nicolas Dos Santos / Alexander Mazeres
 * @version 0.1
 */

class Bullet : public Entity
{
public :
    /**
     * Create a new Bullet
     * @param xPos, yPos position for the Entity
     * @param speed
     */
    Bullet(uint16_t xPos, uint16_t yPos, float speed);

    /**
     * @return true if the bullet is out of the screen
     */
    bool isHit();

    /**
     * reset the position x for the bullet
     * @param xPos
     */
    void reset(uint16_t xPos);

    /**
     *
     */
    void draw();

    /**
     * Update the bullet
     * @return <code>false</code> if the entity should be discarded from the
     * scene, <code>true</code> otherwise
     */
    bool update() override;

private:
    float speed;
    bool hit;
};
#endif