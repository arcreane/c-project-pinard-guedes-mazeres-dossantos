#include "Player.h"


Player::Player(uint16_t xPos, uint16_t yPos, float speed, float delay)
    : Entity(xPos, yPos, IMG_PATH), speed(speed), shootingTimer(0), shootingDelay(delay) {
        maxBullets = 4;
        bullets = new Bullet[4]{
            Bullet(xPos, yPos, speed * 3.0f),
            Bullet(xPos, yPos, speed * 3.0f),
            Bullet(xPos, yPos, speed * 3.0f),
            Bullet(xPos, yPos, speed * 3.0f)
        };
}

Player::Player(uint16_t xPos, uint16_t yPos, float speed)
        : Entity(xPos, yPos, IMG_PATH), speed(speed) {}

void Player::event(){
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_Q))
    {
        xPos -= GetFrameTime() * speed;
        if(xPos < 0) xPos = 0;
    }
    else if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        xPos += GetFrameTime() * speed;
        if(xPos > GetScreenWidth() - xPos) xPos = GetScreenWidth() - xPos;
    }
    else
    {
        xPos = 8;
    }
    if(shootingTimer <= 0.0f && IsKeyPressed(KEY_SPACE))
    {
        for(int i=0; i<maxBullets; i++)
        {
            if(bullets[i].isHit())
            {
                bullets[i].reset(xPos);
                shootingTimer = shootingDelay;
                break;
            }
        }
    }
    else{
        shootingTimer -= GetFrameTime();
    }
}

Player::~Player()
{
    delete[] bullets;
}

bool Player::update(){
    for(int i = 0; i < maxBullets; i++)
    {
        if(bullets[i].isHit())
        {
            bullets[i].update();
        }
    }
    return true;
}

void Player::draw(){
    for(int i = 0; i < maxBullets; i++)
    {
        if(bullets[i].isHit())
        {
            bullets[i].draw();
        }
    }
//    sprite->IMG_PATH;
}
