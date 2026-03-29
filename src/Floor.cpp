#include "Floor.h"

Floor::Floor(int floorNumber) {
    this->floorNumber = floorNumber;
};

void Floor::addWaiting(Passenger p, Direction dir) {
    switch (dir)
    {
    case Direction::UP:
        waitingUp.push(p);
        break;
    case Direction::DOWN:
        waitingDown.push(p);
        break;
    }
};

Passenger Floor::popWaiting(Direction dir) {
    switch (dir)
    {
    case Direction::UP:
        Passenger p = waitingUp.front();
        waitingUp.pop();
        break;
    case Direction::DOWN:
        Passenger p = waitingDown.front();
        waitingDown.pop();
        break;
    }
    //
    return waitingUp.front();
}

bool Floor::hasWaiting(Direction dir) {
    switch (dir)
    {
    case Direction::UP:
        !waitingUp.empty();
        break;
    case Direction::DOWN:
        !waitingDown.empty();
        break;
    }
    return false;
};

int Floor::getNumber() {
    return floorNumber;
};