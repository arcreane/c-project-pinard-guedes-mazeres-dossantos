#include "Player.h"
#include <iostream>

Player::Player(uint16_t xPos, uint16_t yPos, float speed)
        : Entity(xPos, yPos, ASSETS_PATH "players.png", 100), speed(speed) {
    xPos -= sprite.width/2;
}

Player::Player(uint16_t xPos, uint16_t yPos, float speed, float delay)
    : Entity(xPos, yPos, ASSETS_PATH "players.png", 100), speed(speed), shootingTimer(0), shootingDelay(delay) {
        maxBullets = 4;
        bullets = new Bullet[4]{
            Bullet(xPos, yPos, speed * 3.0f),
            Bullet(xPos, yPos, speed * 3.0f),
            Bullet(xPos, yPos, speed * 3.0f),
            Bullet(xPos, yPos, speed * 3.0f)
        };
}

void Player::event(){
    //yPos = GetScreenHeight() - sprite.height;
    // KEY_A and not KEY_Q because raylib keys are for QWERTY keypad
    if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
    {
        xPos -= GetFrameTime() * speed * 7;
        if(xPos < 10) xPos = 10;
    }
    else if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
    {
        xPos += GetFrameTime() * speed * 7 + 0.5;
        if(xPos + sprite.width > GetScreenWidth()) xPos = GetScreenWidth() - sprite.width;
    }
    /*
    else
    {
        xPos = GetScreenWidth() / 2;
    }
     */
    if(shootingTimer <= 0.0f && IsKeyPressed(KEY_SPACE))
    {
        int i;
        for(i=0; i<maxBullets; i++)
        {
            if(bullets[i].isHit())
            {
                draw(bullets[i]);
                shootingTimer = shootingDelay;
                break;
            }
        }
        if(i == maxBullets){
            // no bullet can be use : recharge
            for(i=0; i<maxBullets; i++){
                bullets[i].reset(xPos);
            }
        }
    }
    else{
        shootingTimer -= GetFrameTime() * 5;
    }
}

Player::~Player()
{
    UnloadTexture(this->sprite);
    delete[] bullets;
}

bool Player::update(){
    event();
    for(int i = 0; i < maxBullets; i++)
    {
        if(bullets[i].isHit())
        {
            bullets[i].update();
        }
    }
    return getLife() > 0;
}

void Player::draw(Bullet bullet){
    BeginDrawing();
    bullet.draw(xPos, yPos);
    EndDrawing();
}

double Player::getLife() {
    if(fire_origin_enemy && damage_of_current_attack > 0){
        // Player is attack
        if (xPos_of_fire == xPos){
            this->life -= damage_of_current_attack;
            BeginDrawing();
            DrawText("- ${damages}", xPos, yPos, 2, RED);
            EndDrawing();
            Entity::resetAttackParameters();
        }
    } else if(yPos_of_fire >= yPos) {
        // An enemy is on the heigth of the player : Game Over
        this->life = 0;
    }
    return this->life;
}
