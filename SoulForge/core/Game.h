
#ifndef SOULFORGE_GAME_H
#define SOULFORGE_GAME_H

#include "GameSession.h"
#include "../ui/Menu.h"

class Game {
private:
    Menu menu;
    GameSession session;

    bool running;

    void handleMenuChoice(int choice);

public:
    Game();

    void run();
};

#endif
