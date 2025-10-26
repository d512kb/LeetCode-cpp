// LeetCode.cpp : Defines the entry point for the application.

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> result;
        int minCost = cost[0];

        for (int c : cost) {
            minCost = min(minCost, c);
            result.push_back(minCost);
        }

        return result;
    }
};

int main()
{
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}