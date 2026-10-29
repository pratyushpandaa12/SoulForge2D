
#ifndef SOULFORGE_WORLD_H
#define SOULFORGE_WORLD_H

#include "Location.h"

#include <string>
#include <vector>

class World {
private:
    std::vector<Location> locations;
    int currentLocationIndex;

    int findLocationIndex(const std::string& locationId) const;

public:
    World();

    void initialize();
    void explore();
    void displayCurrentLocation() const;

    const Location* getCurrentLocation() const;
    const std::vector<Location>& getLocations() const;
};

#endif
