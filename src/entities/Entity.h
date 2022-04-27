#pragma once

#include <string>

/**
 * The Entity abstract class defines the basic interface for the entities to be
 * interacted with from the Scene.
 *
 * @author Lucas Pinard (lucasP243)
 * @version 0.1
 */
class Entity {

public:

    /**
     * Creates a new entity.
     * @param[in] xPos, yPos - initial coordinates of the entity
     * @param[in] spritePath - path to the location of the sprite resource
     */
    Entity(uint16_t xPos, uint16_t yPos, std::string spritePath);

    /**
     * Getter for the position of the entity.
     * @param[out] xPos, yPos - coordinates of the entity on the scene
     */
    virtual void getPosition(uint16_t *xPos, uint16_t *yPos) const final = 0;

    /**
     * Getter for the sprite resource for the entity.
     *
     * @return the sprite resource location for the entity
     */
    virtual std::string getSpritePath() const final = 0;

    /**
     * Updates the entity.
     * @return <code>false</code> if the entity should be discarded from the
     * scene, <code>true</code> otherwise
     */
    virtual bool update() = 0;

private:

    /**
     * Path to the sprite resource, relative to
     * <code>/assets/</code>
     */
    const std::string spritePath;

    /**
     * Coordinates of the entity on the scene.
     */
    uint16_t xPos, yPos;

};
