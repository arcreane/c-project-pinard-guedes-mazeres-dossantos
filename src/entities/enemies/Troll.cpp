#include "Troll.h"

Troll::Troll(uint16_t xPos, uint16_t yPos) : Enemy(xPos, yPos, LoadTexture(ASSETS_PATH "troll.png"), 50, 10, 1){}
