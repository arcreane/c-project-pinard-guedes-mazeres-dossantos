#include "Bullet.h"

Bullet::Bullet(uint16_t xPos, uint16_t yPos, float speed)
        : Entity(xPos, yPos, ASSETS_PATH "shoot.png"), speed(speed), hit(true) {}

bool Bullet::update()
{
    yPos -= GetFrameTime() * speed;
    if(yPos < 0 || yPos > GetScreenHeight()) hit = true;
    return true;
}

bool Bullet::isHit()
{
    return hit;
}

void Bullet::reset(uint16_t xPos)
{
    this->xPos = xPos;
    hit = true;
}

void Bullet::draw(uint16_t x, uint16_t y) {
    Vector2 v1 = {static_cast<float>(x + getSprite().width), static_cast<float>(y)};
    Vector2 v2 = {static_cast<float>(x + getSprite().width), 0};
    DrawLineEx(v1, v2, 5, BLACK);
    hit = false;
}
