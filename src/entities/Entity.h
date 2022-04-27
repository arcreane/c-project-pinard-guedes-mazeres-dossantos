#pragma once

#include <cstdint>
#include "raylib.h"

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
     * @param[in] sprite - the sprite texture resource
     */
    Entity(uint16_t xPos, uint16_t yPos, Texture2D sprite);

    /**
     * Getter for the position of the entity.
     * @param[out] xPos, yPos - coordinates of the entity on the scene
     */
    virtual void getPosition(uint16_t *xPos, uint16_t *yPos) const final;

    /**
     * Getter for the sprite image of the entity.
     *
     * @return pointer to the sprite texture resource loaded in CPU
     */
    virtual Texture2D getSprite() const final;

    /**
     * Updates the entity.
     * @return <code>false</code> if the entity should be discarded from the
     * scene, <code>true</code> otherwise
     */
    virtual bool update() = 0;

private:

    /**
     * Sprite texture resource loaded in CPU
     */
    const Texture2D sprite;

    /**
     * Coordinates of the entity on the scene.
     */
    uint16_t xPos, yPos;

};
