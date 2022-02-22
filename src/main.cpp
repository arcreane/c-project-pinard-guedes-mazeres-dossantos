#include "raylib.h"

int main() {
    InitWindow(500, 200, "Hello World");

    while (!WindowShouldClose()) {
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