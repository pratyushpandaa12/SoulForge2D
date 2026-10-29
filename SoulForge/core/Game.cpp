
#include "Game.h"

#include <iostream>

Game::Game()
    : running(true) {
}

void Game::run() {
    while (running) {
        menu.displayMainMenu();

        int choice = menu.getMenuChoice();

        handleMenuChoice(choice);
    }
}

void Game::handleMenuChoice(int choice) {
    switch (choice) {
        case 1:
            session.startNewGame();
            break;

        case 2:
            session.exploreWorld();
            break;

        case 3:
            session.displayPlayerProfile();
            break;

        case 4:
            std::cout << "\nSave/load is not implemented yet.\n";
            break;

        case 5:
            std::cout << "\nSettings are not implemented yet.\n";
            break;

        case 0:
            std::cout << "\nThank you for playing SoulForge!\n";
            running = false;
            break;

        default:
            std::cout << "\nInvalid choice. Please try again.\n";
    }
}
