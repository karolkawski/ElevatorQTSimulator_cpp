#include <vector>
#include "Floor.h"
#pragma once
class Building {
    public:
        Building(int numFloors);

        Floor& getFloor(int n);
        int getNumFloors() const;
        void addFloor(Floor f);
        int getTotalFloors() const;

    private:
        std::vector<Floor> floors;
        int numFloors;
};