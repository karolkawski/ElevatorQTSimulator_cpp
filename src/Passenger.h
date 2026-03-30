#pragma once
class Passenger {
public:
    Passenger(int id, int destFloor);

    int getId() const;
    int getDest() const;
    int incrementWait();
    int getWaitTime() const;

private:
    int id;
    int destFloor;
    int waitTime = 0;
};