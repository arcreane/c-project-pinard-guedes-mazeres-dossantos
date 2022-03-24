#include "Scene.h"
#include "raylib.h"

Scene *Scene::getFirstScene() {
    return new MainMenuScene();
}

Scene *MainMenuScene::draw() {
    BeginDrawing();
    ClearBackground(GetColor(0));
    DrawText("Menu principal, Enter pour aller au jeu", 0, 0, 30, GetColor(0xFFFFFF));
    EndDrawing();

    if (IsKeyPressed(KEY_ENTER)) {
        delete this;
        return new GameScene();
    }
    else return this;
}

Scene *GameScene::draw() {
    BeginDrawing();
    ClearBackground(GetColor(0));
    DrawText("Écran jeu, Échap pour aller au menu", 0, 0, 30, GetColor(0xFFFFFF));
    EndDrawing();

    if (IsKeyPressed(KEY_ESCAPE)) {
        delete this;
        return new MainMenuScene();
    }
    else return this;
}
