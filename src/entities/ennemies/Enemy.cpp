#include "Enemy.h"

Enemy::Enemy(uint16_t xPos, uint16_t yPos, Texture2D sprite, double life, double strength, double firerate) :
    Entity(xPos, yPos, sprite), life {life}, strength {strength}, firerate {firerate} {}

void Enemy::getLife(double* l, double damage){
    this->life -= (damage - damage/this->strength*100);
    *l = this->life;
}

void Enemy::getStrength(double *s) const {
    *s = this->strength;
}

void Enemy::getFirerate(double *f) const {
    *f = this->firerate;
}