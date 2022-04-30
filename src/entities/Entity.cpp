#include "Entity.h"

Entity::Entity(uint16_t xPos, uint16_t yPos, const char spritePath[]) :
    xPos {xPos}, yPos {yPos}, sprite {LoadTexture(spritePath)} {}

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
