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
     * @param xPos, yPos, sprite params for Entity
     * @param life when the life = 0, the ennemy is dead
     * @param strength is the resistance of ennemy when he is attacked
     * @param firerate is the shooting speed in seconds
     */
    Enemy(uint16_t xPos, uint16_t yPos, Texture2D sprite, double life, double strength, double firerate);

    /**
     * Getter for life with a damage if the ennemy is attaqued
     * @param l life
     * @param damage
     */
    virtual void getLife(double* l, double damage = 0) final;

    /**
     * Getter for strength capacity
     * @param s strength
     */
    virtual void getStrength(double* s) const final;

    /**
     * Getter for firerate capacity
     * @param f firerate
     */
    virtual void getFirerate(double* f) const final;

    /**
     * Define programmed enemy movement
     */
    virtual void setNewPosition() = 0;

private:

    /**
     * params for the capacities of an ennemy
     */
    double life, strength, firerate;
};