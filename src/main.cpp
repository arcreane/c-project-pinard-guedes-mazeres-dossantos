#include "Window.h"

int main() {

    Window w = Window();

    while (w.isOpen()) {
        w.draw();
    }
}