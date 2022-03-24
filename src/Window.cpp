#include "Window.h"
#include "raylib.h"

Window::Window() : currentScene{Scene::getFirstScene()} {
    InitWindow(
            Window::WINDOW_WIDTH,
            Window::WINDOW_HEIGHT,
            Window::WINDOW_TITLE
    );
    SetTargetFPS(Window::WINDOW_TARGET_FPS);
    SetExitKey(KEY_F12);
}

bool Window::isOpen() { //NOLINT(readability-convert-member-functions-to-static)
    return !WindowShouldClose();
}

void Window::draw() {
    this->currentScene = this->currentScene->draw();
}
