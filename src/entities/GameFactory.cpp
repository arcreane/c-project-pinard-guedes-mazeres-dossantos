#include "scenes/GameScene.h"
#include "entities/enemies/Enemy.h"
#include "GameFactory.h"

void GameFactory::factoryNewGame(std::vector<Entity *> &list) {

    // TODO: create player when implemented

    GameFactory::factoryNewHorde(list);
}

void GameFactory::factoryNewHorde(std::vector<Entity *> &list) {

    Enemy::resetHordeBehavior();

    //TODO: create enemies when implemented
}