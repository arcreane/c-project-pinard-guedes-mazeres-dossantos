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
     * @param[in] spritePath - path to the sprite texture resource
     * @param[in] life - initial life of the Entity
     */
    Entity(uint16_t xPos, uint16_t yPos, const char spritePath[], double life);

    /**
     * Destructor for Entity, unloads the sprite texture from GPU.
     */
    virtual ~Entity();

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

    /**
     * An entitie may attack, we update and return its life
     * @return life restant of the Entity
     *
     * @author Amélie Guédès (MelyMelo8)
     */
    virtual double getLife() = 0;

    /**
     * Initialize parameters of attack inofensives for all entities
     */
    static void resetAttackParameters();

    /**
     * Edit the parameters of attack for hunting part of entities
     * @param x xPos of attack begin
     * @param y > 0 if an Enemy arrive on end of the screen
     * @param enemy true if an enemy attack, false otherwise
     * @param damage the puissance of the attack
     */
    static void editAttackParameters(uint16_t x, uint16_t y, bool enemy, double damage);

protected:

    /**
     * Sprite texture resource loaded in CPU
     */
    const Texture2D sprite;

    /**
     * Coordinates of the entity on the scene.
     */
    uint16_t xPos, yPos;

    /**
     * The life of the Entity
     */
    double life;

    /**
     * statics attributes for the management of attacks
     * @author Amélie Guédès
     */
    static uint16_t xPos_of_fire;
    static uint16_t yPos_of_fire;
    /**
     * true if an ennemy attack, false if the player attack
     */
    static bool fire_origin_enemy;
    static double damage_of_current_attack;
};
