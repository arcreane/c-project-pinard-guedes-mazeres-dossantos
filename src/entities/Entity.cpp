#include "Entity.h"

#include <utility>

Entity::Entity(uint16_t xPos, uint16_t yPos, std::string spritePath) :
    xPos {xPos}, yPos {yPos}, spritePath {std::move(spritePath)} {}

void Entity::getPosition(uint16_t *x, uint16_t *y) const {
    *x = this->xPos;
    *y = this->yPos;
}

std::string Entity::getSpritePath() const {
    return this->spritePath;
}
