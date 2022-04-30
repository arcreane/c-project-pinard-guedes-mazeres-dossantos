#include "Enemy.h"
#include <cmath>

/**
 * Check if an entity at given position is out of the game bounds.
 * @param pos the y position of the entity
 * @param sprite the entity's sprite
 * @return <code>true</code> if the entity is out of bounds, <code>false</code>
 * otherwise
 */
bool isOutOfBound(uint16_t pos, const Texture2D &sprite) {
    return pos < 0 || pos + sprite.width > GetScreenWidth();
}

Enemy::Enemy(uint16_t xPos, uint16_t yPos, const char spritePath[], double life,
             double strength, double fireRate) :
        Entity(xPos, yPos, spritePath, life), strength{strength},
        fireRate{fireRate} {}

double Enemy::getLife() {
    if(!fire_origin_enemy && damage_of_current_attack > 0){
        if (xPos_of_fire == xPos){
            double damages = (damage_of_current_attack - damage_of_current_attack * this->strength / 100);
            this->life -= damages;
            BeginDrawing();
            DrawText("- ${damages}", xPos, yPos, 2, RED);
            EndDrawing();
        }
    }
    return this->life;
}

void Enemy::getStrength(double *s) const {
    *s = this->strength;
}

void Enemy::getFireRate(double *f) const {
    *f = this->fireRate;
}

bool Enemy::update() {
    uint16_t xNew = this->xPos + Enemy::hordeSpeed;
    uint16_t yNew = this->yPos + (Enemy::hordeShouldAdvance ? 10 : 0);
    if (Enemy::hordeShouldTurnAround || isOutOfBound(xNew, this->sprite)) {
        Enemy::hordeShouldTurnAround = true;
    }
    else {
        this->xPos = xNew;
        this->yPos = yNew;
    }
    return getLife() > 0;
}

void Enemy::resetHordeBehavior() {
    Enemy::hordeSpeed = (int16_t) (abs(Enemy::hordeSpeed) + 1);
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

int16_t Enemy::hordeSpeed = 1;

bool Enemy::hordeShouldAdvance = false;

bool Enemy::hordeShouldTurnAround = false;