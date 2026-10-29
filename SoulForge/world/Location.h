
#ifndef SOULFORGE_LOCATION_H
#define SOULFORGE_LOCATION_H

#include <string>
#include <vector>

class Location {
private:
    std::string id;
    std::string name;
    std::string description;

    std::vector<std::string> connectedLocationIds;
    std::vector<std::string> dungeonIds;
    std::string bossId;
    std::vector<std::string> npcIds;
    std::vector<std::string> questIds;

public:
    Location(
        std::string locationId,
        std::string locationName,
        std::string locationDescription,
        std::vector<std::string> connections = {},
        std::vector<std::string> dungeons = {},
        std::string associatedBossId = {},
        std::vector<std::string> npcs = {},
        std::vector<std::string> quests = {}
    );

    void display() const;

    const std::string& getId() const;
    const std::string& getName() const;
    const std::string& getDescription() const;

    const std::vector<std::string>& getConnectedLocationIds() const;
    const std::vector<std::string>& getDungeonIds() const;
    const std::string& getBossId() const;
    const std::vector<std::string>& getNpcIds() const;
    const std::vector<std::string>& getQuestIds() const;
};

#endif
