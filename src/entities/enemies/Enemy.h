#pragma once

#include "entities/Entity.h"

/**
 * The Enemy abstract class defines the basic interface for the enemies.
 *
 * @author Amélie Guédès (MelyMelo8)
 * @version 0.1
 */
class Enemy : public Entity {
public:

    /**
     * Create a new Enemy
     * @param xPos, yPos, spritePath params for Entity
     * @param life when the life = 0, the enemy is dead
     * @param strength is the resistance of enemy when he is attacked
     * @param fireRate is the shooting speed in seconds
     */
    Enemy(uint16_t xPos, uint16_t yPos, const char spritePath[], double life, double strength, double fireRate);

    /**
     * Getter for life with a damage if the enemy is attacked
     */
    virtual double getLife() final override;

    /**
     * Getter for strength capacity
     * @param s strength
     */
    virtual void getStrength(double* s) const final;

    /**
     * Getter for fireRate capacity
     * @param f fireRate
     */
    virtual void getFireRate(double* f) const final;

    /**
     * Override of the Entity function
     * @return true if the Enemy is alive, and false if he is dead
     */
    bool update() override;

    /**
     * Resets the horde, increasing its speed.
     *
     * @author Lucas Pinard (lucasP243)
     */
    static void resetHordeBehavior();

    /**
     * Updates the horde behavior (to be called after each enemy has been
     * updated).
     *
     * @author Lucas Pinard (lucasP243)
     */
    static void updateHordeBehavior();

private:

    /**
     * params for the capacities of an enemy
     */
    double life, strength, fireRate;

    /**
     * Speed of the enemy, in pixels per frame.
     *
     * @author Lucas Pinard (lucasP243)
     */
    static int16_t hordeSpeed;

    /**
     * Flag indicating whether the enemy should advance.
     *
     * @author Lucas Pinard (lucasP243)
     */
    static bool hordeShouldAdvance;

    /**
     * Flag indicating whether the enemy should change direction.
     *
     * @author Lucas Pinard (lucasP243)
     */
    static bool hordeShouldTurnAround;

};