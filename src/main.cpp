#include "Window.h"
#include "entities/player/Player.h"

#define IMG_PATH "assets/player.png"
#define BULLET_PATH "assets/shoot.png"

int main() {

    Window w = Window();

    Player player(0, 0, IMG_PATH, 32, BULLET_PATH, 2);

    while (w.isOpen()) {
        w.update();
    }
}