
#include "World.h"

#include <iostream>
#include <limits>
#include <string>
#include <utility>

namespace {

int readInteger(const std::string& prompt) {
    int value;

    while (true) {
        std::cout << prompt;

        if (std::cin >> value) {
            return value;
        }

        std::cout << "Invalid input. Enter a number.\n";

        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );
    }
}

} // namespace

World::World()
    : currentLocationIndex(-1) {
}

void World::initialize() {
    locations.clear();

    locations.emplace_back(
        "forgotten_grove",
        "The Forgotten Grove",
        "Ancient trees surround a path covered in glowing runes.",
        std::vector<std::string>{"ruined_shrine"},
        std::vector<std::string>{"grove_ruins"},
        "grove_guardian",
        std::vector<std::string>{"old_hermit"},
        std::vector<std::string>{"first_steps"}
    );

    locations.emplace_back(
        "ruined_shrine",
        "The Ruined Shrine",
        "Broken pillars stand beneath a sky filled with strange stars.",
        std::vector<std::string>{
            "forgotten_grove",
            "hollow_cavern"
        },
        std::vector<std::string>{"shrine_dungeon"},
        "shrine_sentinel",
        std::vector<std::string>{},
        std::vector<std::string>{"broken_altars"}
    );

    locations.emplace_back(
        "hollow_cavern",
        "The Hollow Cavern",
        "Cold air drifts through a cavern carved into dark stone.",
        std::vector<std::string>{"ruined_shrine"},
        std::vector<std::string>{"hollow_cavern_dungeon"},
        "cavern_titan",
        std::vector<std::string>{},
        std::vector<std::string>{"echoes_below"}
    );

    currentLocationIndex = 0;
}

int World::findLocationIndex(const std::string& locationId) const {
    for (std::size_t i = 0; i < locations.size(); ++i) {
        if (locations[i].getId() == locationId) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

const Location* World::getCurrentLocation() const {
    if (currentLocationIndex < 0 ||
        currentLocationIndex >= static_cast<int>(locations.size())) {
        return nullptr;
    }

    return &locations[currentLocationIndex];
}

const std::vector<Location>& World::getLocations() const {
    return locations;
}

void World::displayCurrentLocation() const {
    const Location* current = getCurrentLocation();

    if (current == nullptr) {
        std::cout << "\nNo current location is available.\n";
        return;
    }

    current->display();
}

void World::explore() {
    if (locations.empty() || getCurrentLocation() == nullptr) {
        std::cout << "\nThe world has not been initialized.\n";
        return;
    }

    while (true) {
        const Location* current = getCurrentLocation();

        std::cout << "\n========== WORLD EXPLORATION ==========\n";
        std::cout << "Current location: " << current->getName() << '\n';

        const auto& connections = current->getConnectedLocationIds();

        for (std::size_t i = 0; i < connections.size(); ++i) {
            int destinationIndex = findLocationIndex(connections[i]);

            if (destinationIndex >= 0) {
                std::cout << i + 1 << ". Travel to "
                          << locations[destinationIndex].getName() << '\n';
            }
        }

        std::cout << "-1. Inspect current location\n";
        std::cout << "0. Return to main menu\n";

        int choice = readInteger("Choose an action: ");

        if (choice == 0) {
            std::cout << "\nLeaving exploration...\n";
            return;
        }

        if (choice == -1) {
            displayCurrentLocation();
            continue;
        }

        if (choice < 1 ||
            choice > static_cast<int>(connections.size())) {
            std::cout << "Invalid destination choice.\n";
            continue;
        }

        const std::string& destinationId = connections[choice - 1];
        int destinationIndex = findLocationIndex(destinationId);

        if (destinationIndex < 0) {
            std::cout << "That destination is not registered in the world.\n";
            continue;
        }

        currentLocationIndex = destinationIndex;

        std::cout << "\nYou travel to "
                  << locations[currentLocationIndex].getName() << ".\n";

        displayCurrentLocation();
    }
}
