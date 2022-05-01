#include <entities/player/Player.h>
#include "scenes/GameScene.h"
#include "entities/enemies/Enemy.h"
#include "entities/enemies/Troll.h"
#include "entities/enemies/Zombie.h"
#include "GameFactory.h"

void GameFactory::factoryNewGame(std::vector<Entity *> &list) {

    list.push_back(new Player(GetScreenWidth() / 2, GetScreenHeight() - 200, 32, 2));

    GameFactory::factoryNewHorde(list);
}

void GameFactory::factoryNewHorde(std::vector<Entity *> &list) {

    Enemy::resetHordeBehavior();

    for (int x = 200; x <= 800; x += 100) {
        list.push_back(new Zombie(x, 300));
        list.push_back(new Troll(x, 100));
    }
}