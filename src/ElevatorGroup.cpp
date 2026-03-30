#include "ElevatorGroup.h"
#include <vector>

ElevatorGroup::ElevatorGroup(std::vector<Elevator*> elevators, int minFloor, int maxFloor, int groupId) {
    this->elevators = elevators;
    this->minFloor = minFloor;
    this->maxFloor = maxFloor;
    this->groupId = groupId;
}

bool ElevatorGroup::handles(int f) const {
    return f >= minFloor && f <= maxFloor;
}

std::vector<Elevator*> ElevatorGroup::getElevators() const {
    return elevators;
}

Elevator* ElevatorGroup::getBestElevator(int f) {
    Elevator *best = nullptr;
    int bestDist = INT_MAX;

    for (Elevator* e: elevators) {
        int dist = abs(e->getCurrentFloor() - f);
        if (dist < bestDist) {
            bestDist = dist;
            best = e;
        }
    }

    return best;
}


int ElevatorGroup::getId() const {
    return groupId;
}

int ElevatorGroup::getMinFloor() const {
    return minFloor;
}

int ElevatorGroup::getMaxFloor() const {
    return maxFloor;
}