#include "Window.h"
#include "raylib.h"

Window::Window() : currentScene{Scene::getFirstScene()} {
    InitWindow(
            Window::WINDOW_WIDTH,
            Window::WINDOW_HEIGHT,
            Window::WINDOW_TITLE
    );
    SetTargetFPS(Window::WINDOW_TARGET_FPS);
    SetExitKey(KEY_F4);
}

bool Window::isOpen() { //NOLINT(readability-convert-member-functions-to-static)
    return !WindowShouldClose();
}

void Window::update() {
    this->currentScene->draw();
    this->currentScene = this->currentScene->update();
}