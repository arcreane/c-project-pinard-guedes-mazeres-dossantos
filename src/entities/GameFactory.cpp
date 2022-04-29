#include "scenes/GameScene.h"
#include "entities/enemies/Enemy.h"

void GameScene::factoryNewGame() {

    // TODO: create player when implemented

    this->factoryNewHorde();
}

void GameScene::factoryNewHorde() {

    Enemy::resetHordeBehavior();

    //TODO: create enemies when implemented
}