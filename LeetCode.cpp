// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) { return false; }

        sort(hand.begin(), hand.end());
        unordered_map<int, int> numCounts;

        for (int n : hand) { ++numCounts[n]; }
        for (int n : hand) {
            if (numCounts[n] > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (--numCounts[n++] < 0) { return false; }
                }
            }
        }

        return true;
    }
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}