#pragma once

/**
 * The Scene abstract class encapsulates a virtual canvas pinned to the window,
 * responsible for both containing and drawing its components.
 *
 * @author Lucas Pinard (lucasP243)
 * @version 0.1
 */
class Scene {

public:

    /***
     * Gives the first scene of the scenes tree structure.
     *
     * @return A pointer to the first scene.
     */
    static Scene *getFirstScene();

    /**
     * Draws the scene and updates its components.
     *
     * @return A pointer to the next scene, or <code>this</code> if the scene
     * has not changed.
     */
    virtual Scene *draw() = 0;

};


/**
 * The <code>MainMenuScene</code> class encapsulate the main menu of the game.
 */
class MainMenuScene : public Scene {

public:
    Scene *draw() override;
};


/**
 * The <code>GameScene</code> class encapsulate the main game scene of the game.
 */
class GameScene : public Scene {

public:
    Scene *draw() override;
};
