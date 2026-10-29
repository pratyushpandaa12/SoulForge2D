
#include "Player.h"

#include <iostream>

Player::Player()
    : name("Unknown Warrior"),
      health(100),
      maxHealth(100),
      level(1),
      experience(0) {
}

void Player::initialize(const std::string& playerName) {
    name = playerName;
    health = 100;
    maxHealth = 100;
    level = 1;
    experience = 0;
}

void Player::displayStats() const {
    std::cout << "\n========== PLAYER STATUS ==========\n";
    std::cout << "Name:       " << name << '\n';
    std::cout << "Health:     " << health
              << " / " << maxHealth << '\n';
    std::cout << "Level:      " << level << '\n';
    std::cout << "Experience: " << experience << '\n';
    std::cout << "===================================\n";
}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getMaxHealth() const {
    return maxHealth;
}

int Player::getLevel() const {
    return level;
}

int Player::getExperience() const {
    return experience;
}
