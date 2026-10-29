
#include "Menu.h"

#include <iostream>
#include <limits>

void Menu::displayMainMenu() const {
    std::cout << "\n";
    std::cout << "=================================\n";
    std::cout << "          SOULFORGE\n";
    std::cout << " A Text-Based Mythological RPG\n";
    std::cout << "=================================\n";
    std::cout << "1. Start New Game\n";
    std::cout << "2. Explore World\n";
    std::cout << "3. View Player Profile\n";
    std::cout << "4. Load Game (Coming Soon)\n";
    std::cout << "5. Settings (Coming Soon)\n";
    std::cout << "0. Exit\n";
    std::cout << "=================================\n";
}

int Menu::getMenuChoice() const {
    int choice;

    while (true) {
        std::cout << "Enter your choice: ";

        if (std::cin >> choice) {
            return choice;
        }

        std::cout << "Invalid input. Enter a number.\n";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}
