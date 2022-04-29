#include "Enemy.h"
#include <cmath>

Enemy::Enemy(uint16_t xPos, uint16_t yPos, Texture2D sprite, double life,
             double strength, double fireRate) :
        Entity(xPos, yPos, sprite), life{life}, strength{strength},
        fireRate{fireRate} {}

void Enemy::getLife(double *l, double damage) {
    this->life -= (damage - damage / this->strength * 100);
    *l = this->life;
}

void Enemy::getStrength(double *s) const {
    *s = this->strength;
}

void Enemy::getFireRate(double *f) const {
    *f = this->fireRate;
}

bool Enemy::update() {
    return this->life > 0;
}

void Enemy::resetHordeBehavior() {
    Enemy::hordeSpeed = (int16_t) (abs(Enemy::hordeSpeed) + 10);
    Enemy::hordeShouldAdvance = false;
    Enemy::hordeShouldTurnAround = false;
}

void Enemy::updateHordeBehavior() {
    if (Enemy::hordeShouldTurnAround) {
        Enemy::hordeSpeed *= -1;
    }
    Enemy::hordeShouldAdvance = Enemy::hordeShouldTurnAround;
    Enemy::hordeShouldTurnAround = false;
}

int16_t Enemy::hordeSpeed = 0;

bool Enemy::hordeShouldAdvance = false;

bool Enemy::hordeShouldTurnAround = false;