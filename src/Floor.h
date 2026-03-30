#include <queue>
#include "Passenger.h"
#include "Direction.h"
#pragma once

class Floor {
    public:
        Floor(int floorNumber);

        void addWaiting(Passenger p, Direction dir);
        Passenger popWaiting(Direction dir);
        bool hasWaiting(Direction dir) const;
        int getNumber() const;

    private:
        int floorNumber;
        std::queue<Passenger> waitingUp;
        std::queue<Passenger> waitingDown;
};