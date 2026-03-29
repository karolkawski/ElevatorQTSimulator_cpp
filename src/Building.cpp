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

int Building::getTotalFloors() {
    return floors.size();
};

int Building::getNumFloors() {
    return numFloors;
};