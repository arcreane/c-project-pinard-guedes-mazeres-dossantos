#include "Bullet.h"

Bullet::Bullet(uint16_t xPos, uint16_t yPos, float speed)
        : Entity(xPos, yPos, ASSETS_PATH "shoot.png"), speed(speed), hit(true) {
}

bool Bullet::update()
{
    yPos -= GetFrameTime() * speed;
    if(yPos < 0 || yPos > GetScreenHeight()) hit = true;
    return !this->hit;
}

bool Bullet::isHit()
{
    return hit;
}

void Bullet::reset(uint16_t xPos)
{
    this->xPos = xPos;
    hit = false;
}

void Bullet::draw() {
    DrawRectangleRec({8,8,8,8},{255,255,255,255});
}
