#include "Passenger.h"

Passenger::Passenger(int id, int destFloor){
    this->id = id;
    this->destFloor = destFloor;
}

int Passenger::getId() const {
    return id;
}
int Passenger::getDest() const {
    return destFloor;
}
int Passenger::getWaitTime() const {
    return waitTime;
}
int Passenger::incrementWait() {
    return waitTime++;
}