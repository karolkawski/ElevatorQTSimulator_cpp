#include <queue>
#include "Passenger.h"
#include "Direction.h"

class Floor {
    public:
        Floor(int floorNumber);

        void addWaiting(Passenger p, Direction dir);
        Passenger popWaiting(Direction dir);
        Passenger hasWaiting(Direction dir);
        int getNumber();

    private:
        int floorNumber;
        std::queue<Passenger> waitingUp;
        std::queue<Passenger> waitingDown;
};