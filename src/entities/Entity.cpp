#include "Entity.h"

Entity::Entity(uint16_t xPos, uint16_t yPos, const char spritePath[]) :
    xPos {xPos}, yPos {yPos}, sprite {LoadTexture(spritePath)}, life(0) {}

Entity::~Entity() {
    UnloadTexture(this->sprite);
}

void Entity::getPosition(uint16_t *x, uint16_t *y) const {
    *x = this->xPos;
    *y = this->yPos;
}

Texture2D Entity::getSprite() const {
    return this->sprite;
}

void Entity::resetAttackParameters() {
    Entity::xPos_of_fire = 0;
    Entity::yPos_of_fire = 0;
    Entity::fire_origin_enemy = true;
    Entity::damage_of_current_attack = 0;
}

void Entity::editAttackParameters(uint16_t x, uint16_t y, bool enemy, double damage) {
    Entity::xPos_of_fire = x;
    Entity::yPos_of_fire = y;
    Entity::fire_origin_enemy = enemy;
    Entity::damage_of_current_attack = damage;
}


// initiating the attack's parameters for hurting any entities
uint16_t Entity::xPos_of_fire = 0;
uint16_t Entity::yPos_of_fire = 0;
bool Entity::fire_origin_enemy = true;
double Entity::damage_of_current_attack = 0;