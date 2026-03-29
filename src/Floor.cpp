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
    case Direction::UP: {
        Passenger p = waitingUp.front();
        waitingUp.pop();
        return p;
    }
    case Direction::DOWN: {
        Passenger p = waitingDown.front();
        waitingDown.pop();
        return p;
    }
    }
    //
    return waitingUp.front();
}

bool Floor::hasWaiting(Direction dir) const {
    switch (dir)
    {
    case Direction::UP:
        return !waitingUp.empty();
    case Direction::DOWN:
        return !waitingDown.empty();
    }
    return false;
};

int Floor::getNumber() const {
    return floorNumber;
};