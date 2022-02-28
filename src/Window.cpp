#include "Window.h"
#include "raylib.h"

Window::Window() {
    InitWindow(
            Window::WINDOW_WIDTH,
            Window::WINDOW_HEIGHT,
            Window::WINDOW_TITLE
    );
    SetTargetFPS(Window::WINDOW_TARGET_FPS);
}

bool Window::isOpen() {
    return !WindowShouldClose();
}
