// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) : m_carPlaces{ 0, big, medium, small } {
    }

    bool addCar(int carType) {
        if (m_carPlaces[carType] == 0) { return false; }
        --m_carPlaces[carType];
        return true;
    }

private:
    array<int, 4> m_carPlaces;
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}