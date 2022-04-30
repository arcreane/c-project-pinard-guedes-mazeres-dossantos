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
    Bullet(uint16_t xPos, uint16_t yPos, float speed);
    void Update();
    bool IsHit();
    void Reset(uint16_t xPos);
    void Draw();
    bool update() override;

private:
    float speed;
    bool hit;
};
#endif