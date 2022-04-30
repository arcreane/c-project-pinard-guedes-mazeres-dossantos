#include "Window.h"
#include "entities/player/Player.h"

int main() {

    Window w = Window();

    while (w.isOpen()) {
        w.update();
    }
}