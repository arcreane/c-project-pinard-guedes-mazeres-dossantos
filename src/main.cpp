#include "raylib.h"
#include "Window.h"

int main() {

    Window w = Window();

    while (w.isOpen()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawText(
                "Hello World!",
                50, 50,
                60,
                WHITE
        );
        EndDrawing();
    }
}