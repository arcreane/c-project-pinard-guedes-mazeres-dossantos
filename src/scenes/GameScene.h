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
     * the GPU and saves the score in the leaderboard text file.
     */
    ~GameScene();

    void draw() const override;

    Scene *update() override;

private:

    /**
     * Path to the leaderboard text file.
     */
    static constexpr char LEADERBOARD_PATH[] = "./leaderboard.txt";

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

     /**
      * Initializes the list of entities for a new game.
      */
     void factoryNewGame();

     /**
      * Filling the list of entities with a new horde of enemies.
      */
     void factoryNewHorde();
};
