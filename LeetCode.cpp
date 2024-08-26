// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minK = max(1l, accumulate(piles.begin(), piles.end(), 0l) / h);
        int maxK = *max_element(piles.begin(), piles.end());

        while (minK <= maxK) {
            int k = (minK + maxK) / 2;
            int hours = 0;

            for (int p : piles) {
                hours += (p - 1) / k + 1;

                if (hours > h) {
                    minK = k + 1;
                    break;
                }
            }

            if (hours <= h) {
                maxK = k - 1;
            }
        }

        return minK;
    }
};

int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}