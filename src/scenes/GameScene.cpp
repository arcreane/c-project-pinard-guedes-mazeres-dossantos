#include "GameScene.h"
#include "MainMenuScene.h"
#include "raylib.h"

void GameScene::draw() const {
    BeginDrawing();
    ClearBackground(GetColor(0));
    DrawText("Écran jeu, Échap pour aller au menu", 0, 0, 30, GetColor(0xFFFFFF));
    EndDrawing();
}

Scene *GameScene::update() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        delete this;
        return new MainMenuScene();
    }
    else return this;
}
