// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        const int sz = distance.size();
        int distRight = 0;
        int distLeft = 0;

        for (int i = start; i != destination; i = (i + 1) % sz) {
            distRight += distance[i];
        }

        for (int i = start; i != destination;) {
            --i;
            if (i < 0) { i = sz - 1; }

            distLeft += distance[i];
        }

        return min(distRight, distLeft);
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}