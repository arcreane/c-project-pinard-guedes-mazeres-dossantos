#include <entities/player/Player.h>
#include "scenes/GameScene.h"
#include "entities/enemies/Enemy.h"
#include "entities/enemies/Troll.h"
#include "entities/enemies/Zombie.h"
#include "GameFactory.h"

void GameFactory::factoryNewGame(std::vector<Entity *> &list) {

    // TODO: create player when implemented
    Player player(0, 0, 32, 2);

    GameFactory::factoryNewHorde(list);
}

void GameFactory::factoryNewHorde(std::vector<Entity *> &list) {

    Enemy::resetHordeBehavior();

    for (int x = 200; x <= 800; x += 100) {
        list.push_back(new Troll(x, 100));
        list.push_back(new Zombie(x, 300));
    }
}