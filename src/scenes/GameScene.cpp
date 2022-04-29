#include <fstream>
#include <ctime>
#include <iostream>
#include "GameScene.h"
#include "MainMenuScene.h"
#include "raylib.h"

GameScene::GameScene() :
        background{LoadTexture(ASSETS_PATH "grass.png")} {

    this->factoryNewGame();
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

    for (auto it = this->listEntities.begin(); it != this->listEntities.end(); it++) {
        if((*it)->update() == false) {
            this->listEntities.erase(it);
        }
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
        delete this;
        return new MainMenuScene();
    } else return this;
}
