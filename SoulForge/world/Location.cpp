
#include "Location.h"

#include <iostream>
#include <utility>

Location::Location(
    std::string locationId,
    std::string locationName,
    std::string locationDescription,
    std::vector<std::string> connections,
    std::vector<std::string> dungeons,
    std::string associatedBossId,
    std::vector<std::string> npcs,
    std::vector<std::string> quests
)
    : id(std::move(locationId)),
      name(std::move(locationName)),
      description(std::move(locationDescription)),
      connectedLocationIds(std::move(connections)),
      dungeonIds(std::move(dungeons)),
      bossId(std::move(associatedBossId)),
      npcIds(std::move(npcs)),
      questIds(std::move(quests)) {
}

void Location::display() const {
    std::cout << "\n========== " << name << " ==========\n";
    std::cout << description << '\n';
    std::cout << "====================================\n";
}

const std::string& Location::getId() const {
    return id;
}

const std::string& Location::getName() const {
    return name;
}

const std::string& Location::getDescription() const {
    return description;
}

const std::vector<std::string>& Location::getConnectedLocationIds() const {
    return connectedLocationIds;
}

const std::vector<std::string>& Location::getDungeonIds() const {
    return dungeonIds;
}

const std::string& Location::getBossId() const {
    return bossId;
}

const std::vector<std::string>& Location::getNpcIds() const {
    return npcIds;
}

const std::vector<std::string>& Location::getQuestIds() const {
    return questIds;
}
