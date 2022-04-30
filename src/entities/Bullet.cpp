#include "Bullet.h"

Bullet::Bullet(uint16_t xPos, uint16_t yPos, Texture2D sprite, float speed)
        : Entity(xPos, yPos, sprite), speed(speed), hit(true) {
}

void Bullet::Update()
{
    yPos -= GetFrameTime() * speed;
    if(yPos < -yPos.height || yPos > GetScreenHeight()) hit = true;
}

bool Bullet::IsHit()
{
    return hit;
}

void Bullet::Reset(uint16_t xPos)
{
    this->xPos = xPos;
    hit = false;
}

void Bullet::Draw() {
    DrawRectangleRec({8,8,8,8},{255,255,255,255});
}
