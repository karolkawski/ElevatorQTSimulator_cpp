#include <vector>
#include "Floor.h"

class Building {
    public:
        Building(int numFloors);

        Floor& getFloor(int n);
        int getNumFloors();
        void addFloor(Floor f);
        int getTotalFloors();

    private:
        std::vector<Floor> floors;
        int numFloors;
};