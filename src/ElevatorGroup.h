#pragma once
#include "Elevator.h"

class ElevatorGroup {
    public:
        ElevatorGroup(std::vector<Elevator*> elevators, int minFloor, int maxFloor, int groupId);

        bool handles(int f) const;
        std::vector<Elevator*> getElevators() const;
        Elevator* getBestElevator(int f);
        int getId() const;
        int getMinFloor() const;
        int getMaxFloor() const;

    private:
        std::vector<Elevator*> elevators;
        int minFloor;
        int maxFloor;
        int groupId;
};