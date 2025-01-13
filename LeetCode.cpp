// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        int passIndex = 0;
        int takenPlaces = 0;
        for (int busIndex = 0; busIndex < buses.size(); ++busIndex) {
            takenPlaces = 0;

            while (takenPlaces < capacity && passIndex < passengers.size() && passengers[passIndex] <= buses[busIndex]) {
                ++takenPlaces;
                ++passIndex;
            }
        }

        if (takenPlaces < capacity) {
            if (passIndex == 0 || passengers[passIndex - 1] < buses.back()) { return buses.back(); }
        }

        for (--passIndex; passIndex > 0; --passIndex) {
            if (passengers[passIndex] - passengers[passIndex - 1] > 1) {
                return passengers[passIndex] - 1;
            }
        }

        return passengers.front() - 1;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}