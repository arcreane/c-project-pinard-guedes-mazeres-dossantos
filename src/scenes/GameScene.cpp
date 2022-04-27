#include "GameScene.h"
#include "MainMenuScene.h"
#include "raylib.h"

GameScene::GameScene() :
        background{LoadTexture(ASSETS_PATH "grass.png")} {}

GameScene::~GameScene() {
    UnloadTexture(this->background);
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

    EndDrawing();
}

Scene *GameScene::update() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        delete this;
        return new MainMenuScene();
    } else return this;
}
