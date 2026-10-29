
#ifndef SOULFORGE_GAME_SESSION_H
#define SOULFORGE_GAME_SESSION_H

#include "../characters/Player.h"
#include "../world/World.h"

#include <string>

class GameSession {
private:
    Player player;
    World world;
    bool active;

public:
    GameSession();

    void startNewGame();
    void exploreWorld();
    void displayPlayerProfile() const;

    bool hasActiveGame() const;

    Player& getPlayer();
    const Player& getPlayer() const;

    World& getWorld();
    const World& getWorld() const;
};

#endif
