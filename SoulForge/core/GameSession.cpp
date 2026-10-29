
#include "GameSession.h"

#include <iostream>

GameSession::GameSession()
    : active(false) {
}

void GameSession::startNewGame() {
    std::string playerName;

    std::cout << "\n========== NEW ADVENTURE ==========\n";
    std::cout << "Enter your warrior's name: ";

    std::getline(std::cin >> std::ws, playerName);

    if (playerName.empty()) {
        playerName = "Nameless Warrior";
    }

    player.initialize(playerName);
    world.initialize();
    active = true;

    std::cout << "\nWelcome, " << player.getName() << "!\n";
    std::cout << "Your journey into SoulForge begins.\n";

    player.displayStats();
    world.displayCurrentLocation();
}

void GameSession::exploreWorld() {
    if (!active) {
        std::cout << "\nStart a new game before exploring.\n";
        return;
    }

    world.explore();
}

void GameSession::displayPlayerProfile() const {
    if (!active) {
        std::cout << "\nNo active character. Start a new game first.\n";
        return;
    }

    player.displayStats();
}

bool GameSession::hasActiveGame() const {
    return active;
}

Player& GameSession::getPlayer() {
    return player;
}

const Player& GameSession::getPlayer() const {
    return player;
}

World& GameSession::getWorld() {
    return world;
}

const World& GameSession::getWorld() const {
    return world;
}
