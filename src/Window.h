#pragma once
#include <cstdint>

/**
 * The Window class encapsulates the existence of a window, and defines
 * an simplified interface between the application and the raylib API.
 *
 * @author Lucas Pinard (lucasP243)
 * @version 0.1
 */
class Window {

public:

    // TODO : find out a name for the final product
    static constexpr char WINDOW_TITLE[] = "HELLO WORLD";   ///< Game window title

    static constexpr uint16_t WINDOW_WIDTH = 1600;    ///< Game window resolution (width)
    static constexpr uint16_t WINDOW_HEIGHT = 900;    ///< Game window resolution (height)

    static constexpr uint8_t WINDOW_TARGET_FPS = 60;  ///< Game window target framerate per second

    Window();       ///< Creates a game window (calls the raylib InitWindow)

    bool isOpen();  ///< Check if the window is open (calls the raylib WindowShouldClose)

};
