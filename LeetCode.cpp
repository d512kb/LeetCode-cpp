// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int sz = energyDrinkA.size();

        int64_t dpA[3]{ 0 };
        int64_t dpB[3]{ 0 };

        for (int i = 0; i < sz; ++i) {
            dpA[2] = energyDrinkA[i] + max(dpA[1], dpB[0]);
            dpB[2] = energyDrinkB[i] + max(dpB[1], dpA[0]);

            dpA[0] = dpA[1]; dpA[1] = dpA[2];
            dpB[0] = dpB[1]; dpB[1] = dpB[2];
        }

        return max(dpA[2], dpB[2]);
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}