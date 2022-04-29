#pragma once

/**
 * The GameFactory isolates all dependencies from GameScene to Entity
 * implementations.
 *
 * @author Lucas Pinard (LucasP243)
 * @version 0.1
 */
class GameFactory {

public:

    /**
     * Initializes the list of entities for a new game.
     * @param list the list
     */
    static void factoryNewGame(std::vector<Entity *> &list);

    /**
     * Filling the list of entities with a new horde of enemies.
     * @param list the list
     */
    static void factoryNewHorde(std::vector<Entity *> &list);

private:

    /**
     * Private default constructor to prevent instantiation.
     */
     GameFactory() = default;
};