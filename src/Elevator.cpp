#include "Elevator.h"

Elevator::Elevator(int id, int capacity) {
    this->id = id;
    this->capacity = capacity;
    this->state = ElevatorState::IDLE;
}

void Elevator::addStop(int f) {
    stops.insert(f);
}

void Elevator::boardPassenger(Passenger p) {
    if (!isFull()) {
        passengers.push_back(p);
    }
}

std::vector<Passenger> Elevator::alightPassengers() {
    std::vector<Passenger> alighted;
    std::vector<Passenger> remaining;

    for (Passenger &p : passengers)
    {
        if (p.getDest() == currentFloor) {
            alighted.push_back(p);
        }
        else
        {
            remaining.push_back(p);
        }
    }
    passengers = remaining;
    return alighted;
}

void Elevator::move() {

    if (state == ElevatorState::DOORS_OPEN) {
        return; 
    }

    if (stops.empty()) {
        state = ElevatorState::IDLE;
        return;
    }

    int nearest = *stops.begin();

    if (nearest > currentFloor) {
                currentFloor++;
        state = ElevatorState::MOVING_UP;
      
    } else if (nearest < currentFloor) {
        currentFloor--;
        state = ElevatorState::MOVING_DOWN;
    }

    if (nearest == currentFloor) {
        stops.erase(nearest);
        openDoors();
    }
}

void Elevator::openDoors() {
    state = ElevatorState::DOORS_OPEN;
}

void Elevator::closeDoors() {
    if (stops.empty()) {
        state = ElevatorState::IDLE;
        return;
    }

    int nearest = *stops.begin();
     if (nearest > currentFloor) {
         state = ElevatorState::MOVING_UP;
     }
     else
     {
         state = ElevatorState::MOVING_DOWN;
     }
}

int Elevator::getCurrentFloor() const { return currentFloor; }
ElevatorState Elevator::getState() const { return state; }
int Elevator::getLoad() const { return passengers.size(); }
bool Elevator::isFull() const { return passengers.size() >= capacity; }