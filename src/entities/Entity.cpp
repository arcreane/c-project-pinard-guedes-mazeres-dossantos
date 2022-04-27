#include "Entity.h"

Entity::Entity(uint16_t xPos, uint16_t yPos, Texture2D *sprite) :
    xPos {xPos}, yPos {yPos}, sprite {sprite} {}

void Entity::getPosition(uint16_t *x, uint16_t *y) const {
    *x = this->xPos;
    *y = this->yPos;
}

const Texture2D *Entity::getSpritePath() const {
    return this->sprite;
}
