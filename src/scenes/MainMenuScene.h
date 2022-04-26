#pragma once

#include "Scene.h"

/**
 * The <code>MainMenuScene</code> class encapsulate the main menu of the game.
 */
class MainMenuScene : public Scene {

public:

    void draw() const override;

    Scene *update() override;
};
