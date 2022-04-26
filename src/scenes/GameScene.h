#pragma once

#include "Scene.h"

/**
 * The <code>GameScene</code> class encapsulate the main game scene of the game.
 */
class GameScene : public Scene {

public:

    void draw() const override;

    Scene *update() override;
};
