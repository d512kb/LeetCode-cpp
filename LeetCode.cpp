// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> countOfNums;
        unordered_map<int, int> availableNums;

        for (int n : nums) { ++countOfNums[n]; }

        for (int n : nums) {
            if (countOfNums[n] == 0) { continue; }

            if (availableNums[n] > 0) {
                --countOfNums[n];
                --availableNums[n];
                ++availableNums[n + 1];
            } else {
                if (countOfNums[n + 1] == 0 || countOfNums[n + 2] == 0) { return false; }

                --countOfNums[n];
                --countOfNums[n + 1];
                --countOfNums[n + 2];
                ++availableNums[n + 3];
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