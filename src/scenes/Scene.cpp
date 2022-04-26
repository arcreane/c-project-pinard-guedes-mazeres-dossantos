#include "Scene.h"
#include "MainMenuScene.h"

Scene *Scene::getFirstScene() {
    return new MainMenuScene();
}