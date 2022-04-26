#pragma once

#include <cstdint>
#include "scenes/Scene.h"

/**
 * The Window class encapsulates the existence of a window, and defines a
 * simplified interface between the application and the raylib API.
 *
 * @author Lucas Pinard (lucasP243)
 * @version 0.1
 */
class Window {

public:

    /// Game window title
    static constexpr char WINDOW_TITLE[] = "HELLO WORLD";
    // TODO : find out a name for the final product

    /// Game window resolution (width)
    static constexpr uint16_t WINDOW_WIDTH = 1600;

    /// Game window resolution (height)
    static constexpr uint16_t WINDOW_HEIGHT = 900;

    /// Game window target framerate per second
    static constexpr uint8_t WINDOW_TARGET_FPS = 60;

    /**
     * Creates a game window (calls the raylib InitWindow).
     */
    Window();

    /**
     * Check if the window is open (calls the raylib WindowShouldClose).
     *
     * @return <code>true</code> if the window is closing, <code>false</code>
     * otherwise
     */
    bool isOpen();

    /**
     * Draws the window (delegates to <code>Scene::draw()</code>) and updates the current scene if changed.
     * Implements the <a href="https://refactoring.guru/design-patterns/state">State design pattern</a>.
     */
    void update();

private:

    /// The Scene currently visible in the Window
    Scene *currentScene;

};
