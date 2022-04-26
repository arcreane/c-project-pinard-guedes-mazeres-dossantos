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
     * Draws the scene.
     */
    virtual void draw() const = 0;

    /**
     * Updates the components of the scene.
     *
     * @return A pointer to the next scene, or <code>this</code> if the scene
     * has not changed.
     */
    virtual Scene *update() = 0;

};
