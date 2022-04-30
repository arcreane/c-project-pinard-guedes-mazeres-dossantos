#include "Zombie.h"

Zombie::Zombie(uint16_t xPos, uint16_t yPos) : Enemy(xPos, yPos, LoadTexture(ASSETS_PATH "zombie.png"), 20, 2, 2) {}
