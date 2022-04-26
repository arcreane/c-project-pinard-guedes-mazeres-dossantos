#include "MainMenuScene.h"
#include "GameScene.h"
#include "raylib.h"

void MainMenuScene::draw() const {
    BeginDrawing();
    ClearBackground(GetColor(0));
    DrawText("Menu principal, Enter pour aller au jeu", 0, 0, 30, GetColor(0xFFFFFF));
    EndDrawing();
}

Scene *MainMenuScene::update() {
    if (IsKeyPressed(KEY_ENTER)) {
        delete this;
        return new GameScene();
    }
    else return this;
}