#include "ElevatorState.h"
#include "Passenger.h"
#include <vector>
#include <set>
#pragma once


class Elevator {
    public:
        Elevator(int id, int capacity);

        void addStop(int f);
        void boardPassenger(Passenger p);
        std::vector<Passenger> alightPassengers();
        void move();
        void openDoors();
        void closeDoors();
        ElevatorState getState() const;
        int getCurrentFloor() const;
        int getLoad() const;
        bool isFull() const;

    private:
        int id;
        int currentFloor;
        ElevatorState state;
        int capacity;
        std::vector<Passenger> passengers;
        std::set<int> stops;
};