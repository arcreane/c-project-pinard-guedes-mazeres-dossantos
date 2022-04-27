#pragma once

#include <cstdint>
#include <vector>
#include "Scene.h"
#include "entities/Entity.h"

/**
 * The <code>GameScene</code> class encapsulate the main game scene of the game.
 */
class GameScene : public Scene {

public:

    /**
     * Default constructor of the GameScene class, loads the background
     * texture to the GPU.
     */
    GameScene();

    /**
     * Destructor of the GameScene class, unloads the background texture from
     * the GPU.
     */
    ~GameScene();

    void draw() const override;

    Scene *update() override;

private:

    /**
     * Score for the current game.
     */
    uint64_t score = 0;

    /**
     * List of the entities on the scene.
     */
    std::vector<Entity *> listEntities;

    /**
     * Background texture of the scene.
     */
     Texture2D background;
};
