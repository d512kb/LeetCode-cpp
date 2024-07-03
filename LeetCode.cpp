// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];

        for (int i = 2, sz = cost.size(); i < sz; ++i) {
            int c = min(a, b) + cost[i];
            a = b;
            b = c;
        }

        return min(a, b);
    }
};


int main() {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}