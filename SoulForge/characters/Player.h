
#ifndef SOULFORGE_PLAYER_H
#define SOULFORGE_PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;
    int maxHealth;
    int level;
    int experience;

public:
    Player();

    void initialize(const std::string& playerName);
    void displayStats() const;

    std::string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getLevel() const;
    int getExperience() const;
};

#endif
