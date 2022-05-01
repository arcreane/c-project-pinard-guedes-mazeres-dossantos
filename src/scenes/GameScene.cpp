#include <fstream>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "GameScene.h"
#include "MainMenuScene.h"
#include "raylib.h"
#include "entities/GameFactory.h"
#include "entities/enemies/Enemy.h"
#include "entities/Entity.h"

GameScene::GameScene() :
        background{LoadTexture(ASSETS_PATH "grass.png")} {

    GameFactory::factoryNewGame(this->listEntities);
}

GameScene::~GameScene() {
    UnloadTexture(this->background);

    if (this->score > 0) {
        time_t now = time(nullptr);

        char now_str[100];
        strftime(
                now_str, sizeof now_str,
                "%Y-%m-%d %H:%M:%S",
                localtime(&now)
        );

        std::ofstream out(GameScene::LEADERBOARD_PATH, std::ios::app);
        std::cout << (out.is_open() ? "ok" : "ko") << std::endl;
        out << now_str << " ===== " << this->score << std::endl;
        out.close();
    }
}

void GameScene::draw() const {
    BeginDrawing();

    DrawTextureQuad(
            this->background,
            (Vector2) {
                    (float) GetScreenWidth() / (float) this->background.width,
                    (float) GetScreenHeight() / (float) this->background.height
            },
            (Vector2) {0.0f, 0.0f},
            (Rectangle) {
                    0.0f,
                    0.0f,
                    (float) GetScreenWidth(),
                    (float) GetScreenHeight()
            },
            WHITE
    );

    for (Entity *e: this->listEntities) {
        uint16_t x, y;
        e->getPosition(&x, &y);
        DrawTexture(e->getSprite(), x, y, WHITE);
    }

    EndDrawing();
}

Scene *GameScene::update() {

//    Entity::resetAttackParameters();

    // Update all entities
    for (auto it = this->listEntities.begin();
         it != this->listEntities.end();) {
        if (!(*it)->update()) {
            delete (*it);
            this->listEntities.erase(it);
        } else {
            it++;
        }
    }
    Enemy::updateHordeBehavior();

    // If there is no more enemies, create new horde
    if (std::find_if(
            this->listEntities.begin(), this->listEntities.end(),
            [](Entity *it) -> bool {
                // instanceof
                return dynamic_cast<const Enemy *>(it) != nullptr;
            }) == this->listEntities.end()) {
        GameFactory::factoryNewHorde(this->listEntities);
    }

    // Exit game on Escape press
    if (IsKeyPressed(KEY_ESCAPE)) {
        delete this;
        return new MainMenuScene();
    } else return this;
}
