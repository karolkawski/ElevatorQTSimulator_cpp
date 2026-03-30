#include "Building.h"

Building::Building(int numFloors) {
    for (int i = 0; i < numFloors; i++) {
        floors.push_back(Floor(i));
    }
}

Floor& Building::getFloor(int index) {
    return floors[index];
};

void Building::addFloor(Floor f) {
    floors.push_back(f);
};

int Building::getTotalFloors() const {
    return floors.size();
};

int Building::getNumFloors() const  {
    return numFloors;
};